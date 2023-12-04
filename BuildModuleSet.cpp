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
 * Function : BuildModuleSet
 *****************************************************************************/
BuildModuleSet::BuildModuleSet
(QString InTrackName) : QWidget()
{
  TrackName = InTrackName;
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

/*****************************************************************************!
 * Function : BuildTargetDatabase
 *****************************************************************************/
void
BuildModuleSet::BuildTargetDatabase(void)
{
  MainCodeDatabase->ClearBuildTargets();
  for ( auto module : modules ) {
    module->BuildTargetDatabase();
  }
}

/*****************************************************************************!
 * Function : AddBuildModule
 *****************************************************************************/
void
BuildModuleSet::AddBuildModule
(BuildModule* InModule)
{
  modules << InModule;
  InModule->SetBuildModuleSetParent(this);
}

/*****************************************************************************!
 * Function : ReadDatabases
 *****************************************************************************/
void
BuildModuleSet::ReadDatabases(void)
{
  ReadBuildModules();
  ReadBuildTargets();
  ReadBuildSources();
}

/*****************************************************************************!
 * Function : ReadBuildModules
 *****************************************************************************/
void
BuildModuleSet::ReadBuildModules(void)
{
  MainCodeDatabase->ReadBuildModules(this); 
}

/*****************************************************************************!
 * Function : ReadTargetDatabase
 *****************************************************************************/
void
BuildModuleSet::ReadBuildTargets(void)
{
  for ( auto module : modules ) {
    MainCodeDatabase->ReadBuildTargets(module);
  }
}

/*****************************************************************************!
 * Function : ReadBuildSources
 *****************************************************************************/
void
BuildModuleSet::ReadBuildSources(void)
{
  for ( auto module : modules ) {
    MainCodeDatabase->ReadBuildSources(module);
  }
}

/*****************************************************************************!
 * Function : GetBuildModulesCount
 *****************************************************************************/
int
BuildModuleSet::GetBuildModulesCount(void)
{
  return modules.size();
}

/*****************************************************************************!
 * Function : GetBuildModuleByIndex
 *****************************************************************************/
BuildModule*
BuildModuleSet::GetBuildModuleByIndex
(int InIndex)
{
  if ( InIndex >= modules.size() ) {
    return NULL;
  }
  return modules[InIndex];
}

/*****************************************************************************!
 * Function : GetBuildModuleByName
 *****************************************************************************/
BuildModule*
BuildModuleSet::GetBuildModuleByName
(QString InName)
{
  for ( auto m : modules ) {
    if ( m->GetName() == InName ) {
      return m;
    }
  }
  return NULL;
}

/*****************************************************************************!
 * Function : GetAllBuildSources
 *****************************************************************************/
QList<BuildSource*>
BuildModuleSet::GetAllBuildSources(void)
{
  QList<BuildSource*>                   returnSources;
  QList<BuildSource*>                   sources;

  for ( auto module : modules ) {
    sources = module->GetBuildSources();
    returnSources << sources;
  }
  return returnSources;
}

/*****************************************************************************!
 * Function : GetASTPath
 *****************************************************************************/
QString
BuildModuleSet::GetASTPath(void)
{
  return ASTPath;  
}

/*****************************************************************************!
 * Function : SetASTPath
 *****************************************************************************/
void
BuildModuleSet::SetASTPath
(QString InASTPath)
{
  ASTPath = InASTPath;  
}
