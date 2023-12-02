/*****************************************************************************
 * FILE NAME    : BuildTarget.h
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _buildtarget_h_
#define _buildtarget_h_

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
 * Exported Class : BuildTarget
 *****************************************************************************/
class BuildTarget : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  BuildTarget                   ();

 //! Destructor
 public :
  ~BuildTarget                  ();

 //! Public Methods
 public :
  void                          Set                     (QString InTrackName, QString InType, QString InName, QString InPath);
  QString                       GetType                 (void);
  QString                       GetName                 (void);

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
  QString                       TrackName;
  QString                       Type;
  QString                       Name;
  QString                       Path;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _buildtarget_h_*/
