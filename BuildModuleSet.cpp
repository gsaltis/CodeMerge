/*****************************************************************************
 * FILE NAME    : BuildModuleSet.cpp
 * DATE         : November 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModuleSet.h"
#include "main.h"

/*****************************************************************************!
 * Function : BuildModuleSet
 *****************************************************************************/
BuildModuleSet::BuildModuleSet
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~BuildModuleSet
 *****************************************************************************/
BuildModuleSet::~BuildModuleSet
()
{
}

/*****************************************************************************!
 * Function : GetModuleCount
 *****************************************************************************/
int
BuildModuleSet::GetModuleCount(void)
{
  return modules.size();
}

/*****************************************************************************!
 * Function : GetTrackName
 *****************************************************************************/
QString
BuildModuleSet::GetTrackName(void)
{
  return TrackName;  
}

/*****************************************************************************!
 * Function : SetTrackName
 *****************************************************************************/
void
BuildModuleSet::SetTrackName
(QString InTrackName)
{
  TrackName = InTrackName;  
}

/*****************************************************************************!
 * Function : GetTrackPath
 *****************************************************************************/
QString
BuildModuleSet::GetTrackPath(void)
{
  return TrackPath;  
}

/*****************************************************************************!
 * Function : SetTrackPath
 *****************************************************************************/
void
BuildModuleSet::SetTrackPath
(QString InTrackPath)
{
  TrackPath = InTrackPath;  
}

/*****************************************************************************!
 * Function : BuildDatabase
 *****************************************************************************/
void
BuildModuleSet::BuildDatabase(void)
{
  QString                               filePath;
  QFileInfoList                         subDirs;
  QDir                                  dir(TrackPath);
  QString                               makefileName;

  makefileName = TrackPath + QString("Makefile");
  QFileInfo                                     makeFileInfo(makefileName);
  if ( makeFileInfo.exists() ) {
    BuildModule*                                buildModule;
    TRACE_FUNCTION_QSTRING(TrackPath);
    buildModule = new BuildModule(TrackName, QString("src"), TrackPath);
    MainCodeDatabase->SaveBuildModule(buildModule);
    modules << buildModule;
  }

  subDirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
  for (auto i : subDirs ) {
    filePath = i.filePath();
    BuildDatabase(filePath);
  }
}

/*****************************************************************************!
 * Function : BuildDatabase
 *****************************************************************************/
void
BuildModuleSet::BuildDatabase
(QString InFilePath)
{
  QDir                                  dir(InFilePath);
  QString                               makefileName;
  QString                               filePath;
  QFileInfoList                         subDirs;

  makefileName = InFilePath + QString("/Makefile");
  QFileInfo                                     makeFileInfo(makefileName);
  if ( makeFileInfo.exists() ) {
    BuildModule*                                buildModule;
    int n = TrackPath.length();
    QString s = InFilePath.sliced(n);
    TRACE_FUNCTION_QSTRING(InFilePath);
    buildModule = new BuildModule(TrackName, s, InFilePath);
    MainCodeDatabase->SaveBuildModule(buildModule);
    modules << buildModule;
  }
  subDirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
  for (auto i : subDirs ) {
    filePath = i.filePath();
    BuildDatabase(filePath);
  }
}

