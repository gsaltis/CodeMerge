/*****************************************************************************
 * FILE NAME    : BuildModule.cpp
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
#include <unistd.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModule.h"
#include "main.h"

/*****************************************************************************!
 * Static Data
 *****************************************************************************/
QString
BuildModule::MakeExeName = "C:\\Qt\\Tools\\mingw1120_64\\bin\\make.exe";

QString
BuildModule::MakeExeArgs = "-B -n";

/*****************************************************************************!
 * Function : BuildModule
 *****************************************************************************/
BuildModule::BuildModule
() : QWidget()
{
}

/*****************************************************************************!
 * Function : BuildModule
 *****************************************************************************/
BuildModule::BuildModule
(QString InTrackName, QString InName, QString InFullPathName) : QWidget()
{
  TrackName = InTrackName;
  Name = InName;
  FullPathName = InFullPathName;
}

/*****************************************************************************!
 * Function : ~BuildModule
 *****************************************************************************/
BuildModule::~BuildModule
()
{
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
BuildModule::GetName(void)
{
  return Name;  
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
BuildModule::SetName
(QString InName)
{
  Name = InName;  
}

/*****************************************************************************!
 * Function : GetFullPathName
 *****************************************************************************/
QString
BuildModule::GetFullPathName(void)
{
  return FullPathName;  
}

/*****************************************************************************!
 * Function : SetFullPathName
 *****************************************************************************/
void
BuildModule::SetFullPathName
(QString InFullPathName)
{
  FullPathName = InFullPathName;  
}

/*****************************************************************************!
 * Function : GetTrackName
 *****************************************************************************/
QString
BuildModule::GetTrackName(void)
{
  return TrackName;  
}

/*****************************************************************************!
 * Function : SetTrackName
 *****************************************************************************/
void
BuildModule::SetTrackName
(QString InTrackName)
{
  TrackName = InTrackName;  
}

/*****************************************************************************!
 * Function : Execute
 *****************************************************************************/
int
BuildModule::Execute(QString &InErrors, QString &InOutput)
{
  QProcess                              makeProcess;

  makeProcess.setArguments(MakeExeArgs.split(QRegularExpression("\\s+")));
  makeProcess.setProgram(MakeExeName);
  makeProcess.setWorkingDirectory(FullPathName);
  makeProcess.start();
  makeProcess.waitForFinished();
  InErrors = QString(makeProcess.readAllStandardError());
  InOutput = QString(makeProcess.readAllStandardOutput());
  ProcessOutput(InOutput);
  return makeProcess.exitCode();
}

/*****************************************************************************!
 * Function : BuildTargetDatabase
 *****************************************************************************/
void
BuildModule::BuildTargetDatabase(void)
{
  QString                               errors;
  QString                               output;
  QString                               s;

  s = QString(TrackName) + QString("/") + QString(Name);
  ExecuteSetup();
  Execute(errors, output);
}

/*****************************************************************************!
 * Function : ExecuteSetup
 *****************************************************************************/
void
BuildModule::ExecuteSetup(void)
{
  QString                               envString;
  QString                               fullPath;
  BuildModuleSet*                       buildModuleSet;

  buildModuleSet = MainBuildModules[TrackName];
  
  fullPath = buildModuleSet->GetTrackPath();
  envString = QString("ACU_SOURCE_DIR=") + fullPath;
  putenv(envString.toStdString().c_str());
}

/*****************************************************************************!
 * Function : ProcessOutput
 *****************************************************************************/
void
BuildModule::ProcessOutput
(QString InBuildLine)
{
  QStringList                           elements;
  QStringList                           lines;
  
  lines = InBuildLine.split("\n", Qt::SkipEmptyParts);
  for (auto line : lines ) {
    if ( BuildLineIsCommentLine(line) ) {
      continue;
    }
    elements = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    if ( !BuildLineIsTargetLine(elements[0]) ) {
      continue;
    }
    ProcessBuildTarget(elements);
  }
}

/*****************************************************************************!
 * Function : BuildLineIsCommentLine
 *****************************************************************************/
bool
BuildModule::BuildLineIsCommentLine
(QString InLine)
{
  if ( InLine[0] == '#' ) {
    return true;
  }
  return false;
}

/*****************************************************************************!
 * Function : BuildLineIsTargetLine
 *****************************************************************************/
bool
BuildModule::BuildLineIsTargetLine
(QString InBuildCommand)
{
  if ( InBuildCommand == "gcc" || InBuildCommand == "ar" || InBuildCommand == "ranlib" ) {
    return true;
  }
  return false;
}

/*****************************************************************************!
 * Function : ProcessBuildTarget
 *****************************************************************************/
void
BuildModule::ProcessBuildTarget
(QStringList InElements)
{
  QString                               buildCommand;
  buildCommand = InElements[0];

  if ( buildCommand == "gcc" ) {
    ProcessBuildCompile(InElements);
    return;
  }
  if ( buildCommand == "ar" ) {
    ProcessBuildArchive(InElements);
    return;
  }
  if ( buildCommand == "ranlib" ) {
    ProcessBuildRanlib(InElements);
    return;
  }
}

/*****************************************************************************!
 * Function : ProcessBuildCompile
 *****************************************************************************/
void
BuildModule::ProcessBuildCompile
(QStringList InElements)
{
  QString                               flagID;
  QString                               sourceType;
  QString                               source;
  int                                   i;
  QString                               s;
  QString                               type;
  int                                   n;
  int                                   m;
  QString                               target;

  m = InElements.size();
  n = InElements.indexOf("-o");
  if ( n == -1 ) {
    return;
  }
  n++;
  target = InElements[n];

  type = GetTargetType(target);
  
  s = TrackName + QString("/") + target + "/" + type;
    
  MainCodeDatabase->SaveBuildTarget(TrackName, target, type, Name);
  for ( i = n + 1 ; i < m ; i++ ) {
    source = InElements[i];
    sourceType = "Unknown";

    flagID = source.left(2);
    if ( flagID == "-L" ) {
      continue;
    }
    do {
      QFileInfo                         info(source);
      QString                           suffix = info.suffix();
      if ( flagID == "-l" ) {
        sourceType = "Library";
        source = source.sliced(2);
        break;
      }
      if ( suffix == "c" ) {
        sourceType = "Source";
        break;
      }
      if ( suffix == "o" ) {
        sourceType = "Object";
        break;
      }
      if ( suffix == "a" ) {
        sourceType = "Library";
        break;
      }
    } while (false);
    
    MainCodeDatabase->SaveBuildSource(TrackName, target, source, Name, sourceType);
  }
}

/*****************************************************************************!
 * Function : ProcessBuildArchive
 *****************************************************************************/
void
BuildModule::ProcessBuildArchive
(QStringList )
{
  
}

/*****************************************************************************!
 * Function : ProcessBuildRanlib
 *****************************************************************************/
void
BuildModule::ProcessBuildRanlib
(QStringList )
{
  
}

/*****************************************************************************!
 * Function : GetTargetType
 *****************************************************************************/
QString
BuildModule::GetTargetType
(QString InTargetName)
{
  QString                               type;

  type = "Binary";

  QFileInfo                   info(InTargetName);
  QString                     suffix = info.suffix();

  if ( suffix == "so" ) {
    type = "SharedObject";
  } else if ( suffix == "o") {
    type = "Object";
  } else if ( suffix == "cgi") {
    type = "CGI";
  }
  return type;
}

/*****************************************************************************!
 * Function : AddBuildTarget
 *****************************************************************************/
void
BuildModule::AddBuildTarget
(BuildTarget* InTarget)
{
  Targets << InTarget;
}

/*****************************************************************************!
 * Function : Set
 *****************************************************************************/
void
BuildModule::Set
(QString InTrackName, QString InName, QString InFullPathName)
{
  TrackName = InTrackName;
  Name = InName;
  FullPathName = InFullPathName;
}

/*****************************************************************************!
 * Function : AddBuildSource
 *****************************************************************************/
void
BuildModule::AddBuildSource
(BuildSource* InSource)
{
  Sources << InSource;
}

/*****************************************************************************!
 * Function : GetTargetCount
 *****************************************************************************/
int
BuildModule::GetTargetCount(void)
{
  return Targets.size();
}

/*****************************************************************************!
 * Function : GetSourceCount
 *****************************************************************************/
int
BuildModule::GetSourceCount(void)
{
  return Sources.size();
}

/*****************************************************************************!
 * Function : GetBuildSources
 *****************************************************************************/
QList<BuildSource*>
BuildModule::GetBuildSources(void)
{
  return Sources;
}
