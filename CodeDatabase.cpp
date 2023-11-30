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
  QString                               errorString;
  int                                   n;
  char*                                 e;
  QString                               statement;
  QMessageBox*                          box;

  statement = "DELETE FROM BuildModule;";

  n = sqlite3_exec(Database, statement.toStdString().c_str(), NULL, NULL, &e);
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
 * Function : SaveBuildModule
 *****************************************************************************/
void
CodeDatabase::SaveBuildModule
(BuildModule* InModule)
{
  QString                               errorString;
  int                                   n;
  char*                                 e;
  QString                               statement;
  QMessageBox*                          box;

  statement =
    "INSERT INTO BuildModule VALUES('"   +
    InModule->GetTrackName()            +
    "', '"                              +
    InModule->GetName()                 +
    "', '"                              +
    InModule->GetFullPathName()         +
    "');";

  n = sqlite3_exec(Database, statement.toStdString().c_str(), NULL, NULL, &e);
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