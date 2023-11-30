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
  QString                       Name;
  QString                       FullPathName;
  QString                       TrackName;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _buildmodule_h_*/
