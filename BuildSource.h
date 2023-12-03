/*****************************************************************************
 * FILE NAME    : BuildSource.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _buildsource_h_
#define _buildsource_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : BuildSource
 *****************************************************************************/
class BuildSource : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  BuildSource                   ();
  BuildSource                   (QString InTrackName, QString InTargetName, QString InSourceName, QString InModuleName, QString InSourceType);

 //! Destructor
 public :
  ~BuildSource                  ();

 //! Public Methods
 public :
  void                          Set                     (QString InTrackName, QString InTargetName, QString InSourceName, QString InModuleName, QString InSourceType);
  QString                       GetSourceName           (void);
  QString                       GetModuleName           (void);

  static QString                NormalizeFilename       (QString InName, QString InModuleName, QString InSourcePath);
  class BuildModule*            GetBuildModuleParent    (void);
  void                          SetBuildModuleParent    (class BuildModule* InBuildModuleParent);

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
  QString                               TrackName;
  QString                               TargetName;
  QString                               SourceName;
  QString                               ModuleName;
  QString                               SourceType;
  class BuildModule*                    BuildModuleParent;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _buildsource_h_*/
