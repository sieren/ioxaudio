#import "BackgroundView.h"
#import "StatusItemView.h"
#import "CoreAudioKit/CoreAudioKit.h"
#import "AppKit/AppKit.h"
@class PanelController;

@protocol PanelControllerDelegate <NSObject>

@optional

- (StatusItemView *)statusItemViewForPanelController:(PanelController *)controller;

@end

#pragma mark -

@interface PanelController : NSWindowController <NSWindowDelegate>
{
    BOOL _hasActivePanel;
    __unsafe_unretained BackgroundView *_backgroundView;
    __unsafe_unretained id<PanelControllerDelegate> _delegate;
     CAInterDeviceAudioViewController *_audioDeviceViewController;
}

@property (nonatomic, unsafe_unretained) IBOutlet BackgroundView *backgroundView;
@property (nonatomic, strong) IBOutlet CAInterDeviceAudioViewController* audioDeviceViewController;
@property (nonatomic, strong) IBOutlet NSView* audioDeviceView;

@property (nonatomic) BOOL hasActivePanel;
@property (nonatomic, unsafe_unretained, readonly) id<PanelControllerDelegate> delegate;
@property (nonatomic, strong) IBOutlet NSTextField *copyrightField;

- (id)initWithDelegate:(id<PanelControllerDelegate>)delegate;

- (void)openPanel;
- (void)closePanel;

@end
