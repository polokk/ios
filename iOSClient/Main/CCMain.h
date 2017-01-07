//
//  CCMain.h
//  Crypto Cloud Technology Nextcloud
//
//  Created by Marino Faggiana on 04/09/14.
//  Copyright (c) 2014 TWS. All rights reserved.
//
//  Author Marino Faggiana <m.faggiana@twsweb.it>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AudioToolbox/AudioToolbox.h>

#import "TWMessageBarManager.h"
#import "SSZipArchive.h"
#import "AHKActionSheet.h"
#import "CTAssetSelectionLabel.h"
#import "BKPasscodeViewController.h"
#import "NSString+TruncateToWidth.h"
#import "UINavigationController+CCProgress.h"
#import "CCLoginNCOC.h"
#import "CCCellMain.h"
#import "CCCellMainTransfer.h"
#import "CCAdd.h"
#import "CCMove.h"
#import "CCDetail.h"
#import "CTAssetsPickerController.h"
#import "CCTemplates.h"
#import "CCShareOC.h"
#import "CCShareInfoCMOC.h"
#import "CCNetworking.h"
#import "CCCoreData.h"
#import "CCMove.h"
#import "CCGraphics.h"
#import "CCSection.h"
#import "CCUtility.h"
#import "CCHud.h"
#import "CCMenu.h"
#import "CCControlCenter.h"
#import "CCPeekPop.h"
#import "CCAccountWeb.h"
#import "CCBancomat.h"
#import "CCCartaDiCredito.h"
#import "CCCartaIdentita.h"
#import "CCContoCorrente.h"
#import "CCNote.h"
#import "CCPassaporto.h"
#import "CCPatenteGuida.h"

#ifdef CC
#import "CCShareDB.h"

@interface CCMain : UITableViewController <UITableViewDataSource, UITableViewDelegate, UIActionSheetDelegate, UIGestureRecognizerDelegate, UIDocumentInteractionControllerDelegate, UIViewControllerPreviewingDelegate, CCMoveDelegate, CTAssetsPickerControllerDelegate, BKPasscodeViewControllerDelegate ,CCAddDelegate, UISplitViewControllerDelegate, UIPopoverControllerDelegate, CCNetworkingDelegate, CCShareOCDelegate, CCShareDBDelegate, CCAccountWebDelegate, CCBancomatDelegate, CCCartaDiCreditoDelegate, CCCartaIdentitaDelegate, CCContoCorrenteDelegate, CCNoteDelegate, CCPassaportoDelegate, CCPatenteGuidaDelegate, CCDetailViewDelegate, CCPeekPopDelegate, UIDocumentMenuDelegate, UIDocumentPickerDelegate>

@property (nonatomic, weak) CCShareDB* shareDB;
#endif

#ifdef NC
@interface CCMain : UITableViewController <UITableViewDataSource, UITableViewDelegate, UIActionSheetDelegate, UIGestureRecognizerDelegate, UIDocumentInteractionControllerDelegate, UIViewControllerPreviewingDelegate, CCMoveDelegate, CTAssetsPickerControllerDelegate, BKPasscodeViewControllerDelegate ,CCAddDelegate, UISplitViewControllerDelegate, UIPopoverControllerDelegate, CCNetworkingDelegate, CCShareOCDelegate, CCAccountWebDelegate, CCBancomatDelegate, CCCartaDiCreditoDelegate, CCCartaIdentitaDelegate, CCContoCorrenteDelegate, CCNoteDelegate, CCPassaportoDelegate, CCPatenteGuidaDelegate, CCDetailViewDelegate, CCPeekPopDelegate, UIDocumentMenuDelegate, UIDocumentPickerDelegate>
#endif

@property (nonatomic ,strong) NSString *localServerUrl;

@property BOOL isFolderEncrypted;
@property (nonatomic, weak) NSString *titleMain;
@property (nonatomic, weak) NSString *textBackButton;

@property (nonatomic, weak) CCShareOC* shareOC;

@property (nonatomic, weak) CCDetail *detailViewController;

@property (nonatomic, weak) CCLoginNCOC *loginVC;

- (void)addActionTable;
- (void)returnCreate:(NSInteger)type;

- (void)createFolderCameraUpload;
- (void)createFolder:(NSString *)fileNameFolder folderCameraUpload:(BOOL)folderCameraUpload;
- (void)readFolderWithForced:(BOOL)forced;

- (void)uploadFileAsset:(NSMutableArray *)assets serverUrl:(NSString *)serverUrl cryptated:(BOOL)cryptated session:(NSString *)session;

- (void)progressTask:(NSString *)fileID serverUrl:(NSString *)serverUrl cryptated:(BOOL)cryptated progress:(float)progress;

- (void)reloadTaskButton:(CCMetadata *)metadata;
- (void)cancelTaskButton:(CCMetadata *)metadata reloadTable:(BOOL)reloadTable;
- (void)stopTaskButton:(CCMetadata *)metadata;

- (void)getDataSourceWithReloadTableView;
- (void)getDataSourceWithReloadTableView:(NSString *)directoryID fileID:(NSString *)fileID selector:(NSString *)selector;

- (void)requestSharedByServer;
- (void)requestServerInformation;

- (void)synchronizedFolderGraphicsServerUrl:(NSString *)serverUrl animation:(BOOL)animation;

- (void)clearDateReadDataSource:(NSNotification *)notification;

@end

