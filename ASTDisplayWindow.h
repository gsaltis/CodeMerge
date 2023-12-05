/*****************************************************************************
 * FILE NAME    : ASTDisplayWindow.h
 * DATE         : December 04 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _astdisplaywindow_h_
#define _astdisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <clang-c/Index.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ASTElementWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define ASTDISPLAY_WINDOW_X             200
#define ASTDISPLAY_WINDOW_Y             200
#define ASTDISPLAY_WINDOW_WIDTH         200
#define ASTDISPLAY_WINDOW_HEIGHT        200

/*****************************************************************************!
 * Exported Class : ASTDisplayWindow
 *****************************************************************************/
class ASTDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ASTDisplayWindow              ();

 //! Destructor
 public :
  ~ASTDisplayWindow             ();

 //! Public Methods
 public :
  QString                       GetASTFileName          (void);
  void                          SetASTFileName          (QString InASTFileName);
  uint32_t                      GetLevel                (void);
  void                          SetLevel                (uint32_t  InLevel);
  void                          IncreaseLevel           (void);
  void                          DecreaseLevel           (void);
  static CXChildVisitResult     VisitChildrenCB         (CXCursor InCursor, CXCursor InParent, CXClientData InClientData);
  void                          ProcessASTCursor        (CXCursor InASTCursor);
  QString                       GetFileName             (void);
  void                          SetFileName             (QString InFileName);

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
  void                          ASTProcess              ();
  
 //! Private Data
 private :
  CXTranslationUnit             TranslationUnit;
  QString                       ASTFileName;
  CXCursor                      ASTCursor;
  CXIndex                       ASTIndex;
  ASTElementWindow*             elementWindow;
  uint32_t                      level;
  QString                       FileName;

 //! Public Slots
 public slots :
  void                          SlotCompileSuccess      (QString InASTPath, QString InFileName, QString InErrors, QString InOutput);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _astdisplaywindow_h_*/
