#pragma once

#include <memory>
#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>

#include "abstractworklistdataacquisition.h"
#include "DataTable.h"

#include "ui_ASAP_GUI_Layout.h"

class ASAP_GUI_Window : public QMainWindow
{
	Q_OBJECT

	public:
		explicit ASAP_GUI_Window(AbstractWorklistDataAcquisition* data_acquisition, QWidget *parent = 0);

	private:
		std::unique_ptr<Ui::ASAP_GUI_Layout> m_ui_;
		std::unique_ptr<AbstractWorklistDataAcquisition> m_data_acquisition_;

		QStandardItemModel* m_images_model_;
		QStandardItemModel* m_patients_model_;
		QStandardItemModel* m_studies_model_;
		QStandardItemModel* m_worklist_model_;

		void SetWorklistItems_(const DataTable& items, QStandardItemModel* model);
		void SetPatientsItems_(const DataTable& items, QStandardItemModel* model);
		void SetStudyItems_(const DataTable& items, QStandardItemModel* model);
		void SetImageItems_(const DataTable& items, QStandardItemModel* model);

		void SetImageInfo_(const QList<QVariant>& info_list, QStandardItemModel* model);
		void SetPatientInfo_(const QList<QVariant>& info_list, QStandardItemModel* model);

		void SetHeaders_(std::vector<std::string> headers, QStandardItemModel* model, QAbstractItemView* view);
		void SetSlots_(void);

	private slots:
		void OnWorklistClear_(QModelIndex index, int row, int column);
		void OnPatientsClear_(QModelIndex index, int row, int column);
		void OnStudyClear_(QModelIndex index, int row, int column);

		void OnWorklistSelect_(QModelIndex index);
		void OnPatientSelect_(QModelIndex index);
		void OnStudySelect_(QModelIndex index);
		void OnImageSelect_(QModelIndex index);
};