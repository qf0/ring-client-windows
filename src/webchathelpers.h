/***************************************************************************
 * Copyright (C) 2017-2019 by Savoir-faire Linux                           *
 * Author: Alexandre Viau <alexandre.viau@savoirfairelinux.com>            *
 * Author: Sébastien Blin <sebastien.blin@savoirfairelinux.com>            *
 * Author: Hugo Lefeuvre <hugo.lefeuvre@savoirfairelinux.com>              *
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

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include "api/conversationmodel.h"

QJsonObject buildInteractionJson(lrc::api::ConversationModel& conversationModel,
                                 const uint64_t msgId,
                                 const lrc::api::interaction::Info& interaction);
QString interactionToJsonInteractionObject(lrc::api::ConversationModel& conversationModel,
                                           const uint64_t msgId,
                                           const lrc::api::interaction::Info& interaction);
QString interactionsToJsonArrayObject(lrc::api::ConversationModel& conversationModel,
                                      const std::map<uint64_t,
                                      lrc::api::interaction::Info> interactions);
