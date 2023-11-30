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
  void                          SaveBuildModule         (BuildModule* InModule);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

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