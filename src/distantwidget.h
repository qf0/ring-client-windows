/***************************************************************************
 * Copyright (C) 2019 by Savoir-faire Linux                                *
 * Author: Andreas Traczyk <andreas.traczyk@savoirfairelinux.com>          *
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

#pragma once

#include "videowidgetbase.h"

#include <QPainter>
#include <QWidget>

class DistantWidget : public VideoWidgetBase {
    Q_OBJECT;

public:
    explicit DistantWidget(QWidget* parent = 0);
    ~DistantWidget();

    void setRendererId(const std::string& id);

protected:
    void paintEvent(QPaintEvent* e);

    void paintBackground(QPainter* painter) override;

private:
    std::string id_;

};
