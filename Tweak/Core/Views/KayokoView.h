//
//  KayokoView.h
//  Kayoko
//
//  Created by Alexandra Aurora Göttlicher
//

#import <roothide.h>
#import <UIKit/UIKit.h>
#import "KayokoHistoryTableView.h"
#import "KayokoFavoritesTableView.h"
#import "KayokoPreviewView.h"

static NSUInteger const kFavoritesButtonImageSize = 24;
static NSUInteger const kClearButtonImageSize = 20;

@interface _UIGrabber : UIControl
@end

@interface KayokoView : UIView {
    KayokoTableView* _previewSourceTableView;
    BOOL _isAnimating;
}
@property(nonatomic, retain)UIBlurEffect* blurEffect;
@property(nonatomic, retain)UIVisualEffectView* blurEffectView;
@property(nonatomic, retain)UIView* headerView;
@property(nonatomic, retain)UITapGestureRecognizer* tapGestureRecognizer;
@property(nonatomic, retain)_UIGrabber* grabber;
@property(nonatomic, retain)UILabel* titleLabel;
@property(nonatomic, retain)UIButton* clearButton;
@property(nonatomic, retain)UIButton* favoritesButton;
@property(nonatomic, retain)UIPanGestureRecognizer* panGestureRecognizer;
@property(nonatomic, retain)KayokoHistoryTableView* historyTableView;
@property(nonatomic, retain)KayokoFavoritesTableView* favoritesTableView;
@property(nonatomic, retain)KayokoPreviewView* previewView;
@property(nonatomic, retain)UIImpactFeedbackGenerator* feedbackGenerator;
@property(atomic, assign)BOOL automaticallyPaste;
- (void)showPreviewWithItem:(PasteboardItem *)item;
- (void)show;
- (void)hide;
- (void)reload;
@end
