/*****************************************************************************
 * FILE NAME    : ModuleToolBar.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduletoolbar_h_
#define _moduletoolbar_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CodeMergeCheckBox.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_TOOL_BAR_HEIGHT          25

/*****************************************************************************!
 * Exported Class : ModuleToolBar
 *****************************************************************************/
class ModuleToolBar : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleToolBar                 ();

 //! Destructor
 public :
  ~ModuleToolBar                ();

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
  QPushButton*                  DisplayModulesButton;
  QPushButton*                  DisplaySourceFilesButton;
  QPushButton*                  DisplayTargetsButton;
  CodeMergeCheckBox*            track2CheckBox;
  CodeMergeCheckBox*            track3CheckBox;

 //! Public Slots
 public slots :
  void                          SlotDisplayModulesButtonPushed (void);
  void                          SlotDisplaySourceFilesButtonPushed (void);
  void                          SlotDisplayTargetsButtonPushed (void);

 //! Public Signals
 signals :
  void                          SignalDisplaySource     (void);
  void                          SignalDisplayModules    (void);
  void                          SignalDisplayTargets    (void);
 //! Public Actions
 public :
  QAction*                      ActionDisplayModulesButtonPushed;
  QAction*                      ActionDisplaySourceFilesButtonPushed;
  QAction*                      ActionDisplayTargetsButtonPushed;

};

#endif /* _moduletoolbar_h_*/
