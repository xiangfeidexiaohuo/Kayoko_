//
//  KayokoCore.h
//  Kayoko
//
//  Created by Alexandra (@Traurige)
//

#import "../../Manager/PasteboardManager.h"
#import "Views/KayokoView.h"
#import "substrate.h"
#import <AudioToolbox/AudioToolbox.h>

KayokoView *kayokoView;

NSUserDefaults *preferences;
BOOL pfEnabled;

NSUInteger pfMaximumHistoryAmount;
BOOL pfSaveText;
BOOL pfSaveImages;
BOOL pfAutomaticallyPaste;
BOOL pfAddTranslateOption;
BOOL pfAddSongDotLinkOption;
CGFloat pfHeightInPoints;

BOOL pfPlaySoundEffects;
BOOL pfPlayHapticFeedback;

@interface UIStatusBarWindow : UIWindow
@end
