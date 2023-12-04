/*****************************************************************************
 * FILE NAME    : SourceTreeWindow.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _sourcetreewindow_h_
#define _sourcetreewindow_h_

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
#include "SourceTree.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SOURCE_TREE_WINDOW_X            200
#define SOURCE_TREE_WINDOW_Y            200
#define SOURCE_TREE_WINDOW_WIDTH        200
#define SOURCE_TREE_WINDOW_HEIGHT       200

/*****************************************************************************!
 * Exported Class : SourceTreeWindow
 *****************************************************************************/
class SourceTreeWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SourceTreeWindow              ();

 //! Destructor
 public :
  ~SourceTreeWindow             ();

 //! Public Methods
 public :
  void                          AddModuleSet            (BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2);

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
  void                          CreateConnections       (void);
 
 //! Private Data
 private :
  MainWindowHeader*             header;
  SourceTree*                   sourceTree;

 //! Public Slots
 public slots :
  void                          SlotErrorMessage        (QString InErrorMessage);
  void                          SlotCompileSuccess      (QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput);

 //! Public Signals
 signals :
  void                          SignalErrorMessage      (QString InErrorMessage);
  void                          SignalCompileSuccess    (QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput);

 //! Public Actions
 public :

};

#endif /* _sourcetreewindow_h_*/
