/*****************************************************************************
 * FILE NAME    : CodeDatabase.h
 * DATE         : November 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _codedatabase_h_
#define _codedatabase_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <sqlite3.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModule.h"
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : CodeDatabase
 *****************************************************************************/
class CodeDatabase : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  CodeDatabase                  (QString InDatabaseFilename);

 //! Destructor
 public :
  ~CodeDatabase                 ();

 //! Public Methods
 public :
  QStringList                   GetTrackNames           (void);
  QString                       GetTrackPathByName      (QString InName);
  void                          OpenDatabase            (void);
  void                          ClearBuildModules       (void);
  void                          ClearBuildTargets       (void);
  void                          ClearBuildSources       (void);
  void                          SaveBuildModule         (BuildModule* InModule);
  void                          SaveBuildTarget         (QString InTrackName, QString InTargetName, QString InType, QString InPath);
  void                          SaveBuildSource         (QString InTrackName, QString InTargetName, QString InSourceName, QString InPath, QString InText);
  void                          ReadBuildTargets        (BuildModule* InModule);
  void                          ReadBuildSources        (BuildModule* InModule);
  void                          ReadBuildModules        (BuildModuleSet* InBuildModuleSet);

  static int                    ReadBuildSourcesCB      (void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames);
  static int                    ReadBuildTargetsCB      (void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames);
  static int                    ReadBuildModulesCB      (void* InPointer, int InColumnCount, char** InColumnValues, char** InColumnNames);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          ExecuteStatement        (QString InSQLStatement);

 //! Private Data
 private :
  QString                       DatabaseFilename;
  sqlite3*                      Database;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _codedatabase_h_*/
