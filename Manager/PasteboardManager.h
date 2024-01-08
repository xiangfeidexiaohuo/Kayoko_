//
//  PasteboardManager.h
//  Kayoko
//
//  Created by Alexandra Aurora Göttlicher
//

#import <roothide.h>
#import <UIKit/UIKit.h>
#import "PasteboardItem.h"
#import "../Utils/CommonUtil.h"
#import "../Utils/ImageUtil.h"
#import "../Preferences/NotificationKeys.h"
#import "../Preferences/PreferenceKeys.h"

#define kHistoryPath jbroot(@"/var/mobile/Library/codes.aurora.kayoko/history.json")
#define kHistoryImagesPath jbroot(@"/var/mobile/Library/codes.aurora.kayoko/images/")

static NSString* const kHistoryKeyHistory = @"history";
static NSString* const kHistoryKeyFavorites = @"favorites";

@interface PasteboardManager : NSObject {
    UIPasteboard* _pasteboard;
    NSUInteger _lastChangeCount;
    NSFileManager* _fileManager;
}
@property(atomic, assign)NSUInteger maximumHistoryAmount;
@property(atomic, assign)BOOL saveText;
@property(atomic, assign)BOOL saveImages;
@property(atomic, assign)BOOL automaticallyPaste;
+ (instancetype)sharedInstance;
- (void)pullPasteboardChanges;
- (void)addPasteboardItem:(PasteboardItem *)item toHistoryWithKey:(NSString *)historyKey;
- (void)addOdesliItemFromItem:(PasteboardItem *)item;
- (void)updatePasteboardWithItem:(PasteboardItem *)item fromHistoryWithKey:(NSString *)historyKey shouldAutoPaste:(BOOL)shouldAutoPaste;
- (void)removePasteboardItem:(PasteboardItem *)item fromHistoryWithKey:(NSString *)historyKey shouldRemoveImage:(BOOL)shouldRemoveImage;
- (NSMutableArray *)itemsFromHistoryWithKey:(NSString *)historyKey;
- (PasteboardItem *)latestHistoryItem;
- (UIImage *)imageForItem:(PasteboardItem *)item;
@end

@interface SBApplication : NSObject
@property(nonatomic, readonly)NSString* bundleIdentifier;
@end

@interface UIApplication (Private)
- (SBApplication *)_accessibilityFrontMostApplication;
@end
