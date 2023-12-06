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
  CodeDatabasePathKey           = "Paths/CodeDatabasePath";
  CodeDatabasePathDefault       = "D:\\Source\\Vertiv\\CodeDB\\Code.db";

  ClangPathKey                  = "Tooling/Clang/Path";
  ClangPathDefault              = "D:\\usr\\local\\bin\\clang.exe";

  ClangArgsKey                  = "Tooling/Clang/Args";
  ClangArgsDefault              = "-emit-ast -c -nostdinc -o %1 -isystem %2 -I %3 %4";
  
  ClangStdIncludeDirKey         = "Tooling/Clang/StdIncludeDir";
  ClangStdIncludeDirDefault     = "D:/Source/Vertiv/CodeBase/stdincludes";

  MakePathKey                   = "Tooling/Make/Path";
  MakePathDefault               = "C:\\Qt\\Tools\\mingw1120_64\\bin\\make.exe";

  MakeArgsKey                   = "Tooling/Make/Args";
  MakeArgsDefault               = "-B -n";
  
  CheckAndSet(ClangPathKey, ClangPathDefault);
  CheckAndSet(ClangArgsKey, ClangArgsDefault);

  CheckAndSet(CodeDatabasePathKey, CodeDatabasePathDefault);
  CheckAndSet(ClangStdIncludeDirKey, ClangStdIncludeDirDefault);

  CheckAndSet(MakePathKey, MakePathDefault);
  CheckAndSet(MakeArgsKey, MakeArgsDefault);
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
  QString                               pathName = "Tooling/Clang/Path";
  QString                               defaultValue = "D:\\usr\\local\\bin\\clang.exe";
  if ( ! contains(pathName) ) {
    setValue(pathName, QString(defaultValue));
  }
  clangPath = value(pathName, QString(defaultValue)).toString();
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
  if ( ! contains("Tooling/Clang/Args") ) {
    setValue("Tooling/Clang/Args", defaultArgs);
  }
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
  if ( ! contains("Tooling/Clang/StdIncludDir") ) {
    setValue("Tooling/Clang/StdIncludeDir", QString("D:/Source/Vertiv/CodeBases/stdincludes"));
  }
  st = value("Tooling/Clang/StdIncludeDir", QString("D:/Source/Vertiv/CodeBases/stdincludes")).toString();
    
  return st;
}

/*****************************************************************************!
 * Function : GetCodeDatabasePath
 *****************************************************************************/
QString
MainSettings::GetCodeDatabasePath(void)
{
  QString                               st;

  if ( ! contains(CodeDatabasePathKey) ) {
    SetCodeDatabasePath(CodeDatabasePathDefault);
  }
  st = value(CodeDatabasePathKey, CodeDatabasePathDefault).toString();

  return st;
}

/*****************************************************************************!
 * Function : SetCodeDatabasePath
 *****************************************************************************/
void
MainSettings::SetCodeDatabasePath
(QString InCodeDatabasePath)
{
  setValue(CodeDatabasePathKey, InCodeDatabasePath);
}

/*****************************************************************************!
 * Function : CheckAndSet
 *****************************************************************************/
void
MainSettings::CheckAndSet
(QString InKey, QString InValue)
{
  if ( contains(InKey) ) {
    return;
  }
  setValue(InKey, InValue);
}

/*****************************************************************************!
 * Function : GetMakePath
 *****************************************************************************/
QString
MainSettings::GetMakePath(void)
{
  return value(MakePathKey, MakePathDefault).toString();
}

/*****************************************************************************!
 * Function : SetMakePath
 *****************************************************************************/
void
MainSettings::SetMakePath
(QString InMakePath)
{
  setValue(MakePathKey, InMakePath);
}

/*****************************************************************************!
 * Function : GetMakeArgs
 *****************************************************************************/
QString
MainSettings::GetMakeArgs(void)
{
  return value (MakeArgsKey, MakeArgsDefault).toString();
}

/*****************************************************************************!
 * Function : SetMakeArgs
 *****************************************************************************/
void
MainSettings::SetMakeArgs
(QString InMakeArgs)
{
  setValue(MakeArgsKey, InMakeArgs);
}
