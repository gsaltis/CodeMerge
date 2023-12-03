/*****************************************************************************
 * FILE NAME    : BuildModuleSet.h
 * DATE         : November 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _buildmoduleset_h_
#define _buildmoduleset_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModule.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : BuildModuleSet
 *****************************************************************************/
class BuildModuleSet : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  BuildModuleSet                ();

 //! Destructor
 public :
  ~BuildModuleSet               ();

 //! Public Methods
 public :
  int                           GetModuleCount          (void);
  QString                       GetTrackName            (void);
  void                          SetTrackName            (QString InTrackName);
  QString                       GetTrackPath            (void);
  void                          SetTrackPath            (QString InTrackPath);
  void                          BuildDatabase           (void);
  void                          BuildTargetDatabase     (void);
  void                          AddBuildModule          (BuildModule* InModule);

  void                          ReadBuildModules        (void);
  void                          ReadBuildTargets        (void);
  void                          ReadBuildSources        (void);

  void                          ReadDatabases           (void);
  int                           GetBuildModulesCount    (void);
  BuildModule*                  GetBuildModuleByIndex   (int InIndex);
  BuildModule*                  GetBuildModuleByName    (QString InName);
  QList<BuildSource*>           GetAllBuildSources      (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          BuildDatabase           (QString InFilePath);

 //! Private Data
 private :
  QList<BuildModule*>           modules;
  QString                       TrackName;
  QString                       TrackPath;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _buildmoduleset_h_*/
