/*****************************************************************************
 * FILE NAME    : ModuleWindow.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _modulewindow_h_
#define _modulewindow_h_

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
#include "ModuleSectionWindow.h"
#include "ModuleTree.h"
#include "ModuleContainerWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_WINDOW_WIDTH             300
#define MODULE_WINDOW_MAX_WIDTH         500

/*****************************************************************************!
 * Exported Class : ModuleWindow
 *****************************************************************************/
class ModuleWindow : public QWidget
{
  Q_OBJECT;

  //! Constructors
public :
  ModuleWindow                  ();

  //! Destructor
public :
  ~ModuleWindow                 ();

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
  void                          PostWindowCreateProcess (void);
  void                          CreateConnections       (void);

  //! Private Data
private :
  MainWindowHeader*             header;
  ModuleSectionWindow*          binariesSection;
  ModuleSectionWindow*          librariesSection;
  ModuleSectionWindow*          loadableObjectsSection;
  ModuleSectionWindow*          headersSection;
  ModuleSectionWindow*          othersSection;
  ModuleTree*                   moduleTree;
  ModuleContainerWindow*        moduleWindow;

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

#endif /* _modulewindow_h_*/
