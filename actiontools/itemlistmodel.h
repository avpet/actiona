/*
	Actiona
	Copyright (C) 2005-2016 Jonathan Mercier-Ganady

	Actiona is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actiona is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#ifndef ITEMLISTMODEL_H
#define ITEMLISTMODEL_H

#include "actiontools_global.h"

#include <QStandardItemModel>

namespace ActionTools
{
	class ACTIONTOOLSSHARED_EXPORT ItemListModel : public QStandardItemModel
	{
		Q_OBJECT

	public:
        ItemListModel(QObject *parent = 0);

		virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	};
}

#endif // ITEMLISTMODEL_H
