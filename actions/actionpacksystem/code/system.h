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

#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QStringList>
#include <qmobilityglobal.h>

QTM_BEGIN_NAMESPACE
class QSystemInfo;
class QSystemStorageInfo;
class QSystemDisplayInfo;
class QSystemDeviceInfo;
QTM_END_NAMESPACE

namespace Code
{
	class System : public QObject, public QScriptable
	{
		Q_OBJECT
		Q_ENUMS(DriveType)
		Q_ENUMS(PowerState)
		Q_ENUMS(StorageLocation)
	
	public:
		enum DriveType
		{
			UnknownDrive,
			InternalDrive,
			RemovableDrive,
			RemoteDrive,
			CdromDrive
		};
		enum PowerState
		{
			UnknownState,
			BatteryPower,
			WallPower,
			WallPowerChargingBattery
		};
		enum StorageLocation
		{
			Desktop,
			Documents,
			Fonts,
			Applications,
			Music,
			Movies,
			Pictures,
			Temp,
			Home,
			Data,
			Cache
		};
		
		static QScriptValue constructor(QScriptContext *context, QScriptEngine *engine);
	
		System();
	
	public slots:
		QString toString() const					{ return "System"; }
		QString storageLocationPath(StorageLocation location) const;
		QString storageLocationName(StorageLocation location) const;
		void openUrl(const QString &url) const;
		int screenCount() const;
		QScriptValue availableGeometry(int screen = -1) const;
		QScriptValue screenGeometry(int screen = -1) const;
		int primaryScreen() const;
		bool isVirtualDesktop() const;
		QString currentDirectory() const;
		QString username() const;
		QString variable(const QString &name) const;
		uint timestamp() const;
		QString version() const;
		QString countryCode() const;
		QString language() const;
		QStringList logicalDrives() const;
		qlonglong availableDiskSpace(const QString &drive) const;
		qlonglong totalDiskSpace(const QString &drive) const;
		DriveType driveType(const QString &drive) const;
		int colorDepth(int screenId = -1) const;
		int displayBrightness(int screenId = -1) const;
		int batteryLevel() const;
		PowerState powerState() const;
		QString manufacturer() const;
		QString model() const;
		QString productName() const;
		
	private:
		QTM_PREPEND_NAMESPACE(QSystemInfo) *mSystemInfo;
		QTM_PREPEND_NAMESPACE(QSystemStorageInfo) *mSystemStorageInfo;
		QTM_PREPEND_NAMESPACE(QSystemDisplayInfo) *mSystemDisplayInfo;
		QTM_PREPEND_NAMESPACE(QSystemDeviceInfo) *mSystemDeviceInfo;
	};
}

#endif // SYSTEM_H