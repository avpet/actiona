/*
	Actionaz
	Copyright (C) 2008-2010 Jonathan Mercier-Ganady

	Actionaz is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actionaz is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#include "listparameterdefinition.h"
#include "subparameter.h"
#include "codecombobox.h"
#include "action.h"

namespace ActionTools
{
	ListParameterDefinition::ListParameterDefinition(Category category, const QString &name, const QString &translatedName, QObject *parent)
		: ItemsParameterDefinition(category, name, translatedName, parent),
		mComboBox(0)
	{
	}

	void ListParameterDefinition::buildEditors(Script *script, QWidget *parent)
	{
		ParameterDefinition::buildEditors(script, parent);

		mComboBox = new CodeComboBox(parent);
		mComboBox->setObjectName("value");

		//The second element of the pair are the translated values
		for(int i=0; i<items().first.size(); ++i)
		{
			if(items().first.at(i) == "[header]")
				mComboBox->addItem(items().second.at(i), "header");
			else
				mComboBox->addItem(items().second.at(i));
		}

		addEditor(mComboBox);

		emit editorBuilt();
	}

	void ListParameterDefinition::load(const Action *action)
	{
		const SubParameter &subParameter = action->subParameter(name(), "value");
		mComboBox->setCode(subParameter.isCode());
		mComboBox->setEditText(translatedNameFromOriginalName(subParameter.value().toString()));
	}

	void ListParameterDefinition::save(Action *action)
	{
		action->setSubParameter(name(), "value", mComboBox->isCode(), originalNameFromTranslatedName(mComboBox->currentText()));
	}

	void ListParameterDefinition::setDefaultValues(Parameter &data)
	{
		data.subParameters()["value"].setValue(option("default"));
	}
}