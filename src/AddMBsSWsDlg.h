/*
 * AddMBsSWsDlg.h - Dialog for selecting/adding measuring blocks and switches
 *
 * Copyright © 2008 Comer352l
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ADDMBSSWSDLG_H
#define ADDMBSSWSDLG_H



#include <QtGui>
#include "ui_AddMBsSWsDlg.h"
#include "SSMprotocol.h"



class AddMBsSWsDlg : public QDialog, private Ui::AddMBsSWs_Dialog
{
	Q_OBJECT

private:
	MBSWmetadata_dt *_MBSWmetaList;
	unsigned int *_MBSWmetaList_len;
	MBSWmetadata_dt _unselectedMBsSWs_metaList[1536];
	int _unselectedMBsSWs_metaList_len;

	static bool rowIndexLessThan(const QModelIndex mi_A, const QModelIndex mi_B);
	void setupUiFonts();

public:
	AddMBsSWsDlg(QWidget *parent, mbsw_dt supportedMBs[768], unsigned int nrofsupportedMBs,
		     mbsw_dt supportedSWs[768], unsigned int nrofsupportedSWs,
		     MBSWmetadata_dt *MBSWmetaList, unsigned int *MBSWmetaList_len);
	~AddMBsSWsDlg();

private slots:
	void add();
	void cancel();
	void setAddButtonEnableStatus();

};



#endif

