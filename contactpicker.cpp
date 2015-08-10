/***************************************************************************
 * Copyright (C) 2015 by Savoir-faire Linux                                *
 * Author: Edric Ladent Milaret <edric.ladent-milaret@savoirfairelinux.com>*
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 **************************************************************************/

#include "contactpicker.h"
#include "ui_contactpicker.h"

#include "categorizedcontactmodel.h"

ContactPicker::ContactPicker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactPicker),
    personSelected_(nullptr)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);

    auto personModel = PersonModel::instance();
    ui->contactView->setModel(personModel);
}

ContactPicker::~ContactPicker()
{
    delete ui;
}

void
ContactPicker::on_contactView_doubleClicked(const QModelIndex &index)
{
    personSelected_ =  index.data(static_cast<int>(Person::Role::Object)).value<Person*>();
    this->accept();
}

Person*
ContactPicker::getPersonSelected()
{
    return personSelected_;
}

void
ContactPicker::on_cancelButton_clicked()
{
    this->reject();
}