/*****************************************************************************
 * FILE NAME    : BuildModule.h
 * DATE         : November 30 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _buildmodule_h_
#define _buildmodule_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildTarget.h"
#include "BuildSource.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : BuildModule
 *****************************************************************************/
class BuildModule : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  BuildModule                   ();
  BuildModule                   (QString InTrackName, QString InName, QString InFullPath);
  
 //! Destructor
 public :
  ~BuildModule                  ();

 //! Public Methods
 public :
  QString                       GetName                 (void);
  void                          SetName                 (QString InName);
  QString                       GetFullPathName         (void);
  void                          SetFullPathName         (QString InFullPathName);
  QString                       GetTrackName            (void);
  void                          SetTrackName            (QString InTrackName);
  int                           Execute                 (QString &InErrors, QString &InOutput);
  void                          BuildTargetDatabase     (void);
  void                          AddBuildTarget          (BuildTarget* InTarget);
  void                          AddBuildSource          (BuildSource* InSource);
  void                          Set                     (QString InTrackName, QString InName, QString InFullPathName);
  int                           GetTargetCount          (void);
  int                           GetSourceCount          (void);
  QList<BuildSource*>           GetBuildSources         (void);
  class BuildModuleSet*         GetBuildModuleSetParent (void);
  void                          SetBuildModuleSetParent (class BuildModuleSet* InBuildModuleSetParent);

 //! Public Data
 public :
  static QString                MakeExeName;
  static QString                MakeExeArgs;
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          ExecuteSetup            (void);
  void                          ProcessOutput           (QString InBuildLine);
  bool                          BuildLineIsCommentLine  (QString InLine);
  bool                          BuildLineIsTargetLine   (QString InBuildCommand);
  void                          ProcessBuildTarget      (QStringList InElements);
  void                          ProcessBuildCompile     (QStringList InElements);
  void                          ProcessBuildArchive     (QStringList InElements);
  void                          ProcessBuildRanlib      (QStringList InElements);
  QString                       GetTargetType           (QString InTargetName);
  void                          Initialize              (void);

 //! Private Data
 private :
  QString                       Name;
  QString                       FullPathName;
  QString                       TrackName;
  QList<BuildTarget*>           Targets;
  QList<BuildSource*>           Sources;
  class BuildModuleSet*         BuildModuleSetParent;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _buildmodule_h_*/
