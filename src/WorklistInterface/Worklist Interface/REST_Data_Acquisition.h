#ifndef __REST_DATA_AQUISITION_H__
#define __REST_DATA_AQUISITION_H__

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#include "abstractworklistdataacquisition.h"
#include "DataTable.h"

#include <cpprest/http_client.h>

namespace ASAP::Worklist::Data
{
	struct DjangoRestURI
	{
		std::wstring base_url;
		std::wstring worklist_addition;
		std::wstring patient_addition;
		std::wstring study_addition;
		std::wstring image_addition;
		std::wstring worklist_patient_relation_addition;
	};

	web::json::object GetTagRecursive(std::wstring tag, const web::json::value& json);

	int ParseJsonToRecords(const web::http::http_response& response, DataTable& table);
	int ParseJsonToTable(const web::http::http_response& response, DataTable& table);

	class DjangoDataAcquisition //: public AbstractWorklistDataAcquisition
	{
		public:
			DjangoDataAcquisition(const DjangoRestURI uri_info);

			size_t GetWorklistRecords(const std::function<void(DataTable, const int)>& receiver);
			size_t GetPatientRecords(const std::function<void(DataTable, const int)>& receiver, const size_t worklist_index);
			size_t GetStudyRecords(const std::function<void(DataTable, const int)>& receiver, const size_t patient_index);
			size_t GetImageRecords(const std::function<void(DataTable, const int)>& receiver, const size_t study_index);

			std::vector<std::string> GetPatientHeaders(void);
			std::vector<std::string> GetStudyHeaders(void);
			std::vector<std::string> GetImageHeaders(void);

			void CancelTask(const size_t task_id);

		private:
			enum TableEntry { WORKLIST, PATIENT, STUDY, IMAGE, WORKLIST_PATIENT_RELATION };


			struct TokenTaskPair
			{
				pplx::task<void>						task;
				concurrency::cancellation_token_source	token;
			};


			std::vector<DataTable>	m_tables_;

			web::http::client::http_client				m_client_;
			DjangoRestURI								m_rest_uri_;
			size_t										m_token_counter_;
			std::unordered_map<size_t, TokenTaskPair>	m_active_tasks_;

			void InitializeTables_(void);
			size_t ProcessRequest_(const web::http::http_request& request, std::function<void(web::http::http_response&)> observer);
	};
}
#endif // __REST_DATA_AQUISITION_H__