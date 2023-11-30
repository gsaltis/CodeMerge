/*****************************************************************************
 * FILE NAME    : ModuleSectionWindow.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _modulesectionwindow_h_
#define _modulesectionwindow_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_SECTION_WINDOW_X         200
#define MODULE_SECTION_WINDOW_Y         200
#define MODULE_SECTION_WINDOW_WIDTH     200
#define MODULE_SECTION_WINDOW_HEIGHT    200

/*****************************************************************************!
 * Exported Class : ModuleSectionWindow
 *****************************************************************************/
class ModuleSectionWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleSectionWindow           (QString InTitleText);

 //! Destructor
 public :
  ~ModuleSectionWindow          ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  MainWindowHeader*             header;
  QString                       titleText;
  QColor                        HeaderStartingColor;
  QColor                        HeaderEndingColor;
  QColor                        StartingColor;
  QColor                        EndingColor;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _modulesectionwindow_h_*/
