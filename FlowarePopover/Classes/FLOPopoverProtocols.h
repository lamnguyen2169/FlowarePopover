//
//  FLOPopoverProtocols.h
//  FlowarePopover
//
//  Created by Lam Nguyen on 5/30/19.
//  Copyright © 2019 Floware Inc. All rights reserved.
//

#ifndef FLOPopoverProtocols_h
#define FLOPopoverProtocols_h

#import <Cocoa/Cocoa.h>

@protocol FLOPopoverProtocols <NSObject>

@property (nonatomic, assign, readonly) NSRect frame;
@property (nonatomic, assign, readonly, getter = isShown) BOOL shown;

/**
 * The positioning frame that used in displaying function. (only available for given frame displaying).
 */
@property (nonatomic, assign, readonly) NSRect initialPositioningFrame;


@property (nonatomic, assign) BOOL alwaysOnTop;
@property (nonatomic, assign) BOOL shouldShowArrow;
@property (nonatomic, assign) NSSize arrowSize;
@property (nonatomic, assign) BOOL animated;
@property (nonatomic, assign) BOOL animatedForwarding;
@property (nonatomic, assign) CGFloat bottomOffset;

@property (nonatomic, assign) BOOL staysInApplicationFrame;
@property (nonatomic, assign) BOOL updatesFrameWhileShowing;
@property (nonatomic, assign) BOOL shouldRegisterSuperviewObservers;
@property (nonatomic, assign) BOOL shouldChangeSizeWhenApplicationResizes;
@property (nonatomic, assign) BOOL closesWhenPopoverResignsKey;
@property (nonatomic, assign) BOOL closesWhenApplicationBecomesInactive;
@property (nonatomic, assign) BOOL closesWhenApplicationResizes;
@property (nonatomic, assign) BOOL closesWhenNotBelongToContainerFrame;
@property (nonatomic, assign) BOOL closesWhenReceivesEvent;

/**
 * Make the popover movable.
 */
@property (nonatomic, assign) BOOL isMovable;

/**
 * Make the popover detach from its parent window.
 */
@property (nonatomic, assign) BOOL isDetachable;

/**
 * Set tag for the popover.
 */
@property (nonatomic, assign) NSInteger tag;

/**
 * Make transition animation by moving frame of the popover instead of using CALayer.
 */
@property (nonatomic, assign) BOOL animatedByMovingFrame;

@property (nonatomic, assign) NSTimeInterval animationDuration;

@property (nonatomic, assign) BOOL needAutoresizingMask;

#pragma mark - Callback utilities

@property (nonatomic, copy) void (^willShowBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^didShowBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^willCloseBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^didCloseBlock)(id<FLOPopoverProtocols> popover);

@property (nonatomic, copy) void (^didMoveBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^didDetachBlock)(id<FLOPopoverProtocols> popover);

#pragma mark - Initialize

/**
 * Initialize the FLOPopover with content view and type is FLOViewPopover by default.
 *
 * @param contentView the view needs displayed on FLOPopover
 * @return FLOPopover instance
 */
- (id)initWithContentView:(NSView *)contentView;

/**
 * Initialize the FLOPopover with content view controller and type is FLOViewPopover by default.
 *
 * @param contentViewController the view controller needs displayed on FLOPopover
 * @return FLOPopover instance
 */
- (id)initWithContentViewController:(NSViewController *)contentViewController;

#pragma mark - Utilities

- (void)setAnimationBehaviour:(FLOPopoverAnimationBehaviour)animationBehaviour type:(FLOPopoverAnimationType)animationType animatedInAppFrame:(BOOL)animatedInAppFrame;

/**
 * Update the popover to new contentView while it's displaying.
 *
 * @param contentView the new content view needs displayed on the popover.
 */
- (void)setPopoverContentView:(NSView *)contentView;
- (void)setPopoverContentViewController:(NSViewController *)contentViewController;

/**
 * Re-arrange the popover with new content view size.
 *
 * @param newSize new size of content view.
 */
- (void)setPopoverContentViewSize:(NSSize)newSize;
- (void)setPopoverPositioningRect:(NSRect)rect;
- (void)setPopoverPositioningView:(NSView *)positioningView positioningRect:(NSRect)rect;
- (void)setPopoverContentViewSize:(NSSize)newSize positioningRect:(NSRect)rect;

- (void)shouldShowArrowWithVisualEffect:(BOOL)needed material:(NSVisualEffectMaterial)material blendingMode:(NSVisualEffectBlendingMode)blendingMode state:(NSVisualEffectState)state;


/**
 * Sticking rect: Display the popover relative to the rect of positioning view
 *
 * @param rect is the rect that popover will be displayed relatively to.
 * @param positioningView is the view that popover will be displayed relatively to.
 * @param edgeType 'position' that the popover should be displayed.
 *
 * @note rect is bounds of positioningView.
 * @note positioningView is also a sender that sends event for showing the popover (positioningView ≡ sender).
 */
- (void)showRelativeToRect:(NSRect)rect ofView:(NSView *)positioningView edgeType:(FLOPopoverEdgeType)edgeType;

/**
 * Given rect: Dipslay the popover at the given rect with selected view.
 *
 * @param positioningView the view that popover should be displayed relatively at.
 * @param rect the given rect that popover should be displayed at.
 * @param sender view that sends event for showing the popover.
 * @param relativePositionType the specific position that the popover should be displayed relatively to positioningView.
 * @param edgeType 'position' that the popover should be displayed to the anchor view.
 *
 * @note positioningView and sender are different together.
 * @note rect MUST be a value on screen rect (MUST convert to screen rect by [convertRectToScreen:] method).
 * @note If relativePositionType is FLOPopoverRelativePositionAutomatic. It means that the anchor view constraints will be calculated automatically based on the given frame.
 * @warning If you provide the wrong positioningView, sender, or rect, it will lead the strange behaviour on showing.
 */
- (void)showRelativeToView:(NSView *)positioningView withRect:(NSRect)rect sender:(NSView *)sender relativePositionType:(FLOPopoverRelativePositionType)relativePositionType edgeType:(FLOPopoverEdgeType)edgeType;

- (void)close;

@optional
/// For FLOWindowPopover only
///
@property (nonatomic, assign) BOOL resignsFieldsOnClosing;

/**
 * Make Popover window become key, order front and also activate the application.
 * Only available for FLOWindowPopover
 */
@property (nonatomic, assign) BOOL makesKeyAndOrderFrontOnDisplaying;

/**
 * Make the popover become key window. Only apply for FLOWindowPopover type.
 */
@property (nonatomic, assign) BOOL canBecomeKey;

/**
 * Set level for popover. Only used for FLOWindowPopover type.
 *
 * @param level the level of window popover.
 */
- (void)setPopoverLevel:(NSWindowLevel)level;

/**
 * Display popover as system alert style for presented window.
 *
 * @param presentedWindow the target window that the popover will be alerted on.
 */
- (void)showWithAlertStyleForWindow:(NSWindow *)presentedWindow;

@end

#endif /* FLOPopoverProtocols_h */