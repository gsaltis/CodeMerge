/*****************************************************************************
 * FILE NAME    : MainSettings.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsettings_h_
#define _mainsettings_h_

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
 * Exported Class : MainSettings
 *****************************************************************************/
class MainSettings : public QSettings
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSettings                  (QString InOrgName, QString InAppName);

 //! Destructor
 public :
  ~MainSettings                 ();

 //! Public Methods
 public :
  void                          GetMainWindowGeometry   (QPoint &InPosition, QSize &InSize);
  void                          SetMainWindowGeometry   (QPoint InPosition, QSize InSize);
  QFont                         GetTreeHeaderFont       (void);
  QString                       GetClangPath            (void);
  QString                       GetClangArgs            (void);
  QString                       GetClangStdIncludeDir   (void);
  QString                       GetCodeDatabasePath     (void);
  void                          SetCodeDatabasePath     (QString InCodeDatabasePath);
  QString                       GetMakePath             (void);
  void                          SetMakePath             (QString InMakePath);
  QString                       GetMakeArgs             (void);
  void                          SetMakeArgs             (QString InMakeArgs);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          CheckAndSet             (QString InKey, QString InValue);

 //! Private Data
 private :
  QString                       CodeDatabasePathKey;
  QString                       CodeDatabasePathDefault;

  QString                       ClangPathKey;
  QString                       ClangPathDefault;

  QString                       ClangArgsKey;
  QString                       ClangArgsDefault;

  QString                       ClangStdIncludeDirKey;
  QString                       ClangStdIncludeDirDefault;

  QString                       MakePathKey;
  QString                       MakePathDefault;

  QString                       MakeArgsKey;
  QString                       MakeArgsDefault;

  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainsettings_h_*/
