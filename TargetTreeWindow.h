/*****************************************************************************
 * FILE NAME    : TargetTreeWindow.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _targettreewindow_h_
#define _targettreewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindowHeader.h"
#include "TargetTree.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TARGET_TREE_WINDOW_X            200
#define TARGET_TREE_WINDOW_Y            200
#define TARGET_TREE_WINDOW_WIDTH        200
#define TARGET_TREE_WINDOW_HEIGHT       200

/*****************************************************************************!
 * Exported Class : TargetTreeWindow
 *****************************************************************************/
class TargetTreeWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TargetTreeWindow              ();

 //! Destructor
 public :
  ~TargetTreeWindow             ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  MainWindowHeader*             header;
  TargetTree*                   targetTree;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _targettreewindow_h_*/
