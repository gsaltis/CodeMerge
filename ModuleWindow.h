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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_WINDOW_WIDTH             300

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

  //! Private Data
private :
  MainWindowHeader*             header;
  ModuleSectionWindow*          binariesSection;
  ModuleSectionWindow*          librariesSection;
  ModuleSectionWindow*          loadableObjectsSection;
  ModuleSectionWindow*          headersSection;
  ModuleSectionWindow*          othersSection;
  ModuleTree*                   moduleTree;

  //! Public Slots
public slots :

  //! Public Signals
signals :

  //! Public Actions
public :

};

#endif /* _modulewindow_h_*/
