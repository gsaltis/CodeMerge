/*****************************************************************************
 FILE NAME      : main.cpp
 DATE           : November 29 2023
 PROJECT        : CodeMerge
 COPYRIGHT      : Copyright (C) 2023 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QApplication>
#include <QCommandLineParser>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>
#include <sqlite3.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "main.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainCreateBuildModuleSets
(void);

void
MainOpenCodeDatabase
();

void
MainCreateBuildTargets
();

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
QString
MainOrgName = "Vertiv";

QString
MainAppName = "CodeMerge";

MainSettings*
MainSystemSettings;

QHash<QString, BuildModuleSet*>
MainBuildModules;

CodeDatabase*
MainCodeDatabase;

bool
MainCreateDatabases = false;

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QSize                                 s;
  QPoint                                p;
  QApplication 				application(argc, argv);
  MainWindow* 				w;
  QCommandLineParser                    commandLineParser;
  
  application.setApplicationName("CodeMerge");
  application.setApplicationVersion("0.0.0");
  application.setOrganizationName("Greg Saltis");
  application.setOrganizationDomain("www.gsaltis.com");

  commandLineParser.setApplicationDescription("Code Merge Tool");
  commandLineParser.addHelpOption();
  commandLineParser.addVersionOption();
  
  QCommandLineOption                    createDBOption(QStringList() << "d" << "database", QString("Create new database items"));
  commandLineParser.addOption(createDBOption);
  commandLineParser.process(application);
                                                       
  TRACE_COMMAND_CLEAR();
  MainCreateDatabases = commandLineParser.isSet(createDBOption);

  MainSystemSettings = new MainSettings(MainOrgName, MainAppName);
  MainOpenCodeDatabase();
  if ( MainCreateDatabases ) {
    MainCreateBuildModuleSets();
    MainCreateBuildTargets();
  }
  
  w = new MainWindow(NULL);
  MainSystemSettings->GetMainWindowGeometry(p, s);
  w->resize(s);
  w->move(p);
  w->show();
  
  return application.exec();
}

/*****************************************************************************!
 * Function : MainCreateBuildModuleSets
 *****************************************************************************/
void
MainCreateBuildModuleSets
(void)
{
  BuildModuleSet*                       buildModule;
  QString                               trackPath;
  QString                               trackName;
  int                                   n;
  QStringList                           trackNames;

  TRACE_FUNCTION_LOCATION();
  MainCodeDatabase->ClearBuildModules();
  trackNames = MainCodeDatabase->GetTrackNames();
  n = trackNames.size();
  for (int i = 0; i < n; i++) {
    trackName = trackNames[i];
    trackPath = MainCodeDatabase->GetTrackPathByName(trackName);
    buildModule = new BuildModuleSet();
    buildModule->SetTrackName(trackName);
    buildModule->SetTrackPath(trackPath);
    buildModule->BuildDatabase();
    MainBuildModules[trackName] = buildModule;
  }
}

/*****************************************************************************!
 * Function : MainOpenCodeDatabase
 *****************************************************************************/
void
MainOpenCodeDatabase
()
{
  MainCodeDatabase = new CodeDatabase("D:\\Source\\Vertiv\\CodeDB\\Code.db");
  MainCodeDatabase->OpenDatabase();
}

/*****************************************************************************!
 * Function : MainCreateBuildTargets
 *****************************************************************************/
void
MainCreateBuildTargets
()
{
  BuildModuleSet*                       moduleSet;
  QStringList                           trackNames;

  TRACE_FUNCTION_LOCATION();
  trackNames = MainCodeDatabase->GetTrackNames();

  MainCodeDatabase->ClearBuildTargets();
  MainCodeDatabase->ClearBuildSources();
  
  for ( auto trackName : trackNames ) {
    moduleSet = MainBuildModules[trackName];
    TRACE_FUNCTION_LOCATION();
    moduleSet->BuildTargetDatabase();
  }
}
