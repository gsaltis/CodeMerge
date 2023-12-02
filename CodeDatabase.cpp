/*****************************************************************************
 * FILE NAME    : CodeDatabase.cpp
 * DATE         : November 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMessageBox>
#include <unistd.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CodeDatabase.h"
#include "BuildModule.h"

/*****************************************************************************!
 * Function : CodeDatabase
 *****************************************************************************/
CodeDatabase::CodeDatabase
(QString InDatabaseFilename) : QWidget()
{
  DatabaseFilename = InDatabaseFilename;
}

/*****************************************************************************!
 * Function : ~CodeDatabase
 *****************************************************************************/
CodeDatabase::~CodeDatabase
()
{
}

/*****************************************************************************!
 * Function : GetTrackNames
 *****************************************************************************/
QStringList
CodeDatabase::GetTrackNames(void)
{
  QStringList                           trackNames;
  QString                               trackName;
  int                                   retries;
  bool                                  finished;
  QString                               errorString;
  QString                               selectStatement;
  sqlite3_stmt*                         statement;
  QMessageBox*                          box;
  int                                   n;
  
  selectStatement = "SELECT TrackName from Track;";

  n = sqlite3_prepare_v2(Database,
                         selectStatement.toStdString().c_str(),
                         selectStatement.length(),
                         &statement,
                         NULL);
  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_prepare_v2() FAIL\n"
                          "%1 %2\n"
                          "%3\n"
                          "%4").arg(__FILE__).arg(__LINE__).arg(selectStatement).arg(sqlite3_errstr(n));
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_open() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }

  finished = false;
  retries = 0;
  
  while ( ! finished ) {
    n = sqlite3_step(statement);
    switch (n) {
      case SQLITE_BUSY : {
        usleep(25000);
        retries++;
        if ( retries == 3 ) {
          finished = true;
        }
        break;
      }
      case SQLITE_DONE : {
        finished = true;
        break;
      }
      case SQLITE_ROW : {
        trackName = QString((char*)sqlite3_column_text(statement, 0));
        trackNames << trackName;
        break;
      }
      case SQLITE_ERROR : {
        finished = true;
        break;
      }
      case SQLITE_MISUSE : {
        finished = true;
        break;
      }
    }
  }
  sqlite3_finalize(statement);
  return trackNames;
}

/*****************************************************************************!
 * Function : GetTrackPathByName
 *****************************************************************************/
QString
CodeDatabase::GetTrackPathByName
(QString InName)
{
  QString                               trackPath;
  int                                   retries;
  bool                                  finished;
  QString                               errorString;
  QString                               selectStatement;
  sqlite3_stmt*                         statement;
  QMessageBox*                          box;
  int                                   n;
  
  selectStatement = QString("SELECT BasePath from Track WHERE TrackName is \"%1\";").arg(InName);

  n = sqlite3_prepare_v2(Database,
                         selectStatement.toStdString().c_str(),
                         selectStatement.length(),
                         &statement,
                         NULL);
  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_prepare_v2() FAIL\n"
                          "%1 %2\n"
                          "%3\n"
                          "%4").arg(__FILE__).arg(__LINE__).arg(selectStatement).arg(sqlite3_errstr(n));
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_open() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }

  finished = false;
  retries = 0;
  
  while ( ! finished ) {
    n = sqlite3_step(statement);
    switch (n) {
      case SQLITE_BUSY : {
        usleep(25000);
        retries++;
        if ( retries == 3 ) {
          finished = true;
        }
        break;
      }
      case SQLITE_DONE : {
        finished = true;
        break;
      }
      case SQLITE_ROW : {
        trackPath = QString((char*)sqlite3_column_text(statement, 0));
        finished = true;
        break;
      }
      case SQLITE_ERROR : {
        finished = true;
        break;
      }
      case SQLITE_MISUSE : {
        finished = true;
        break;
      }
    }
  }
  sqlite3_finalize(statement);
  return trackPath;
}

/*****************************************************************************!
 * Function : OpenDatabase
 *****************************************************************************/
void
CodeDatabase::OpenDatabase(void)
{
  QString                               errorString;
  int                                   n;
  QMessageBox*                          box;

  n = sqlite3_open(DatabaseFilename.toStdString().c_str(), &Database);

  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_open() FAIL\n"
                          "%1 %2\n"
                          "%3").arg(__FILE__).arg(__LINE__).arg(sqlite3_errstr(n));
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_open() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }  
}

/*****************************************************************************!
 * Function : ClearBuildModules
 *****************************************************************************/
void
CodeDatabase::ClearBuildModules(void)
{
  QString                               statement;

  statement = "DELETE FROM BuildModule;";
  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : ClearBuildSources
 *****************************************************************************/
void
CodeDatabase::ClearBuildSources(void)
{
  QString                               statement;

  statement = "DELETE FROM BuildSource;";
  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : ClearBuildTargets
 *****************************************************************************/
void
CodeDatabase::ClearBuildTargets(void)
{
  QString                               statement;

  statement = "DELETE FROM BuildTarget;";
  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : SaveBuildModule
 *****************************************************************************/
void
CodeDatabase::SaveBuildModule
(BuildModule* InModule)
{
  QString                               statement;
  statement =
    "INSERT INTO BuildModule VALUES('"  +
    InModule->GetTrackName()            +
    "', '"                              +
    InModule->GetName()                 +
    "', '"                              +
    InModule->GetFullPathName()         +
    "');";

  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : SaveBuildTarget
 *****************************************************************************/
void
CodeDatabase::SaveBuildTarget
(QString InTrackName, QString InTargetName, QString InType, QString InPath)
{
  QString                               statement;

  statement =
    "INSERT INTO BuildTarget VALUES('"  +
    InTrackName                         +
    "', '"                              +
    InType                              +
    "', '"                              +
    InTargetName                        +
    "', '"                              +
    InPath                              +
    "');";

  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : SaveBuildSource
 *****************************************************************************/
void
CodeDatabase::SaveBuildSource
(QString InTrackName, QString InTargetName, QString InSourceName, QString InPath, QString InText)
{
  QString                               statement;

  statement =
    "INSERT INTO BuildSource VALUES('"  +
    InTrackName                         +
    "', '"                              +
    InTargetName                        +
    "', '"                              +
    InSourceName                        +
    "', '"                              +
    InPath                              +
    "', '"                              +
    InText                              +
    "');";

  ExecuteStatement(statement);
}

/*****************************************************************************!
 * Function : ExecuteStatement
 *****************************************************************************/
void
CodeDatabase::ExecuteStatement
(QString InSQLStatement)
{
  QString                               errorString;
  int                                   n;
  char*                                 e;
  QMessageBox*                          box;

  n = sqlite3_exec(Database, InSQLStatement.toStdString().c_str(), NULL, NULL, &e);
  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_exec() FAIL\n"
                          "%1 %2\n"
                          "%3\n"
                          "%4").arg(__FILE__).arg(__LINE__).arg(InSQLStatement).arg(e);
    
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_exec() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }  
}
 

/*****************************************************************************!
 * Function : ReadBuildTargets
 *****************************************************************************/
void
CodeDatabase::ReadBuildTargets
(BuildModule* InModule)
{
  QString                               errorString;
  int                                   n;
  char*                                 e;
  QMessageBox*                          box;
  QString                               statement;

  statement = QString("SELECT * FROM BuildTarget WHERE TrackName is '%1';").arg(InModule->GetTrackName());

  n = sqlite3_exec(Database, statement.toStdString().c_str(), ReadBuildTargetsCB, InModule, &e);
  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_exec() FAIL\n"
                          "%1 %2\n"
                          "%3\n"
                          "%4").arg(__FILE__).arg(__LINE__).arg(statement).arg(e);
    
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_exec() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }  
}

/*****************************************************************************!
 * Function : ReadBuildTargetsCB
 *****************************************************************************/
int
CodeDatabase::ReadBuildTargetsCB
(void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames)
{
  BuildTarget*                          buildTarget;
  QString                               trackName;
  QString                               type;
  QString                               name;
  QString                               path;
  QString                               columnName;
  int                                   i;
  QString                               columnValue;
  BuildModule*                          buildModule;

  buildModule = (BuildModule*)InPointer;

  for (i = 0; i < InColumnCount; i++) {
    columnValue = InColumnValues[i];
    columnName  = InColumnNames[i];

    if ( columnName == "TrackName" ) {
      trackName = columnValue;
      continue;
    }
    if ( columnName == "Type" ) {
      type = columnValue;
      continue;
    }
    if ( columnName == "Name" ) {
      name != columnValue;
      continue;
    }
    if ( columnName == "Path" ) {
      path != columnValue;
      continue;
    }
  }

  buildTarget = new BuildTarget();
  buildTarget->Set(trackName, type, name, path);
  buildModule->AddBuildTarget(buildTarget);
  return 0;
}

/*****************************************************************************!
 * Function : ReadBuildModules
 *****************************************************************************/
void
CodeDatabase::ReadBuildModules
(BuildModuleSet* InBuildModuleSet)
{
  QString                               errorString;
  int                                   n;
  char*                                 e;
  QMessageBox*                          box;
  QString                               statement;

  statement = QString("SELECT * FROM BuildModule WHERE TrackName is '%1' ORDER BY Name;").arg(InBuildModuleSet->GetTrackName());

  n = sqlite3_exec(Database, statement.toStdString().c_str(), ReadBuildModulesCB, InBuildModuleSet, &e);
  if ( n != SQLITE_OK ) {
    errorString = QString("sqlite3_exec() FAIL\n"
                          "%1 %2\n"
                          "%3\n"
                          "%4").arg(__FILE__).arg(__LINE__).arg(statement).arg(e);
    
    box = new QMessageBox(QMessageBox::Critical, "sqlite3_exec() FAIL",
                          errorString);
    box->exec();
    exit(EXIT_FAILURE);
  }    
}

/*****************************************************************************!
 * Function : ReadBuildModulesCB
 *****************************************************************************/
int
CodeDatabase::ReadBuildModulesCB
(void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames)
{
  BuildModuleSet*                       buildModuleSet;
  QString                               trackName;
  QString                               type;
  QString                               name;
  QString                               path;
  QString                               columnName;
  int                                   i;
  QString                               columnValue;
  BuildModule*                          buildModule;

  buildModuleSet = (BuildModuleSet*)InPointer;

  for (i = 0; i < InColumnCount; i++) {
    columnValue = InColumnValues[i];
    columnName  = InColumnNames[i];

    if ( columnName == "TrackName" ) {
      trackName = columnValue;
      continue;
    }
    if ( columnName == "Name" ) {
      name = columnValue;
      continue;
    }
    if ( columnName == "FullPath" ) {
      path = columnValue;
      continue;
    }
  }

  buildModule = new BuildModule();
  buildModule->Set(trackName, name, path);
  buildModuleSet->AddBuildModule(buildModule);
  return 0;
}

