/*****************************************************************************
 * FILE NAME    : MainSettings.cpp
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSettings.h"
#include "MainWindow.h"

/*****************************************************************************!
 * Function : MainSettings
 *****************************************************************************/
MainSettings::MainSettings
(QString InOrgName, QString InAppName) : QSettings(InOrgName, InAppName)
{
}

/*****************************************************************************!
 * Function : ~MainSettings
 *****************************************************************************/
MainSettings::~MainSettings
()
{
}

/*****************************************************************************!
 * Function : GetMainWindowGeometry
 *****************************************************************************/
void
MainSettings::GetMainWindowGeometry
(QPoint &InPosition, QSize &InSize)
{
  int                                   x, y, width, height;

  x = value("MainWindow/Geometry/X", MAIN_WINDOW_X).toInt();
  y = value("MainWindow/Geometry/Y", MAIN_WINDOW_Y).toInt();
  width = value("MainWindow/Geometry/WIDTH", MAIN_WINDOW_WIDTH).toInt();
  height = value("MainWindow/Geometry/Height", MAIN_WINDOW_HEIGHT).toInt();

  InPosition.setX(x);
  InPosition.setY(y);
  InSize.setWidth(width);
  InSize.setHeight(height);
}

/*****************************************************************************!
 * Function : SetMainWindowGeometry
 *****************************************************************************/
void
MainSettings::SetMainWindowGeometry
(QPoint InPosition, QSize InSize)
{
  setValue("MainWindow/Geometry/X", InPosition.x());
  setValue("MainWindow/Geometry/Y", InPosition.y());
  setValue("MainWindow/Geometry/Width", InSize.width());
  setValue("MainWindow/Geometry/Height", InSize.height());
}

/*****************************************************************************!
 * Function : GetTreeHeaderFont
 *****************************************************************************/
QFont
MainSettings::GetTreeHeaderFont
(void)
{
  return QFont("Segoe UI", 10, QFont::Bold);
}

/*****************************************************************************!
 * Function : GetClangPath
 *****************************************************************************/
QString
MainSettings::GetClangPath
(void)
{
  QString                               clangPath;

  clangPath = value("Tooling/Clang/Path", QString("D:\\usr\\local\\bin\\clang.exe")).toString();
  return clangPath;
}

/*****************************************************************************!
 * Function : GetClangArgs
 *****************************************************************************/
QString
MainSettings::GetClangArgs
(void)
{
  QString                               defaultArgs;
  QString                               args;

  defaultArgs = QString("-emit-ast -c -nostdinc -o %1 -isystem %2 -I %3 %4");
  args = value("Tooling/Clang/Args", defaultArgs).toString();
  
  return args;
}

/*****************************************************************************!
 * Function : GetClangStdIncludeDir
 *****************************************************************************/
QString
MainSettings::GetClangStdIncludeDir(void)
{
  QString                               st;

  st = value("Tooling/Clang/StdIncludeDir", QString("D:/Source/Vertiv/CodeBases/stdincludes")).toString();
  return st;
}

