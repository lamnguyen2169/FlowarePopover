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

#import "FLOPopoverUtils.h"

@protocol FLOPopoverProtocols <NSObject>

@property (nonatomic, weak, readonly) NSResponder *representedObject;

@property (nonatomic, assign, readonly) NSRect frame;
@property (nonatomic, assign, readonly, getter = isShown) BOOL shown;
@property (nonatomic, assign, readonly) FLOPopoverType type;
@property (nonatomic, assign, readonly) FLOPopoverStyle popoverStyle;
@property (nonatomic, assign, readonly) BOOL containsArrow;

/// Determine whether the popover can be interacted.
@property (nonatomic, assign, readonly) BOOL userInteractionEnable;

/// The dim color of disable view when the popover interaction is disabled.
@property (nonatomic, strong, readonly) NSColor *disabledColor;

/**
 * This is used for checking purpose, when the utilities received
 * the content view's frame changed notification.
 * For updating the popover frame correctly instead of unnecessary notification.
 */
@property (nonatomic, assign) BOOL localUpdated;

@property (nonatomic, assign) NSRect initialFrame;

@property (nonatomic, strong) FLOPopoverUtils *utils;

@property (nonatomic, assign) BOOL isShowing;
@property (nonatomic, assign) BOOL isClosing;
@property (nonatomic, assign) BOOL closeEventReceived;

@property (nonatomic, assign) BOOL hasShadow;
@property (nonatomic, assign) BOOL shouldShowArrow;
@property (nonatomic, assign) NSSize arrowSize;
@property (nonatomic) CGColorRef arrowColor;
@property (nonatomic, assign) BOOL animated;
@property (nonatomic, assign) BOOL animatedForwarding;
@property (nonatomic, assign) CGFloat bottomOffset;
/**
 * This maximum height the popover could be set.
 */
@property (nonatomic, assign) CGFloat maxHeight;

@property (nonatomic, assign) BOOL stopsAtContainerBounds;

/**
 * Determine whether the popover should stay in screen.
 * Default value of staysInScreen is NO, it means that the popover will keep its orginal frame
 * without fitting its frame to the container.
 */
@property (nonatomic, assign) BOOL staysInScreen;
/**
 * Determine whether the popover should stay in container.
 * Default value of staysInContainer is NO, it means that the popover will keep its orginal frame
 * without fitting its frame to the container.
 */
@property (nonatomic, assign) BOOL staysInContainer;
/**
 * Update the position of the popover when its NSRectEdge changed by circular direction.
 * Default value of staysInContainer is YES.
 * @code NSRectEdgeMinX (backward) --> NSRectEdgeMaxY (above) --> NSRectEdgeMaxX (forward) --> NSRectEdgeMinY (below) @endcode
 * If the value of staysInContainer is set as NO, it means that
 * the popover's position will be updated with cross direction.
 * @code NSRectEdgeMinX (backward) --> NSRectEdgeMaxX (forward) --> NSRectEdgeMinY (below) --> NSRectEdgeMaxY (above) @endcode
 */
@property (nonatomic, assign) BOOL updatesPositionCircularly;
@property (nonatomic, assign) BOOL updatesFrameWhileShowing;
@property (nonatomic, assign) BOOL updatesFrameWhenApplicationResizes;
@property (nonatomic, assign) BOOL shouldUseRelativeVisibleRect;
@property (nonatomic, assign) BOOL shouldRegisterSuperviewObservers;
@property (nonatomic, assign) BOOL shouldChangeSizeWhenApplicationResizes;
@property (nonatomic, assign) BOOL closesWhenPopoverResignsKey;
@property (nonatomic, assign) BOOL closesWhenApplicationBecomesInactive;
@property (nonatomic, assign) BOOL closesWhenApplicationResizes;
@property (nonatomic, assign) BOOL closesWhenNotBelongToContainer;
@property (nonatomic, assign) BOOL closesWhenReceivesEvent;

/**
 * Make popover become key, order front when mouse hovers the popover
 */
@property (nonatomic, assign) BOOL becomesKeyOnMouseOver;

/**
 * Make the popover movable.
 */
@property (nonatomic, assign) BOOL isMovable;

/**
 * Make the popover detach from its parent window.
 */
@property (nonatomic, assign) BOOL isDetachable;

/**
 * Set the styleMask for detachable window.
 */
@property (nonatomic, assign) NSWindowStyleMask detachableStyleMask;

/**
 * Set tag for the popover.
 */
@property (nonatomic, assign) NSInteger tag;

@property (nonatomic, assign) NSTimeInterval animationDuration;

#pragma mark - Callback utilities

@property (nonatomic, copy) void (^floPopoverWillShowBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverDidShowBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) BOOL (^floPopoverShouldCloseBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverWillCloseBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverDidCloseBlock)(id<FLOPopoverProtocols> popover);

@property (nonatomic, copy) void (^floPopoverWillMoveBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverDidMoveBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverWillDetachBlock)(id<FLOPopoverProtocols> popover);
@property (nonatomic, copy) void (^floPopoverDidDetachBlock)(id<FLOPopoverProtocols> popover);

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
/**
 * Sticking rect: Re-arrange the popover with new positioningView and edgeType.
 *
 * @param positioningView is the view that popover will be displayed relatively to.
 * @param edgeType 'position' that the popover should be displayed.
 *
 * @note positioningView is also a sender that sends event for showing the popover (positioningView ≡ sender).
 */
- (void)setPopoverPositioningView:(NSView *)positioningView edgeType:(FLOPopoverEdgeType)edgeType;
/**
 * Sticking rect: Re-arrange the popover with new positioningView, edgeType and positioningRect.
 *
 * @param positioningView is the view that popover will be displayed relatively to.
 * @param edgeType 'position' that the popover should be displayed.
 * @param rect 'position' that the popover should be displayed.
 *
 * @note positioningView is also a sender that sends event for showing the popover (positioningView ≡ sender).
 */
- (void)setPopoverPositioningView:(NSView *)positioningView edgeType:(FLOPopoverEdgeType)edgeType positioningRect:(NSRect)rect;

/// Determine whether the popover can be interacted.
- (void)setUserInteractionEnable:(BOOL)isEnabled;

/// The dim color of disable view when the popover interaction is disabled.
- (void)setDisabledColor:(NSColor *)disabledColor;

- (void)showWithVisualEffect:(BOOL)needed material:(NSVisualEffectMaterial)material blendingMode:(NSVisualEffectBlendingMode)blendingMode state:(NSVisualEffectState)state;

- (void)updateFrame:(NSRect)frame;
- (void)updatePopoverFrame;

/// Invalidate the popover shadow in case of changing position of popover arrow
/// or other case the popover shadow not updated when popover moves.
- (void)invalidateShadow;

/// Invalidate the arrow color of popover in case of the view of contentView or
/// contentViewController changed its background color.
- (void)invalidateArrowPathColor;

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
@property (nonatomic, assign) BOOL becomesKeyAfterDisplaying;

/**
 * Make the popover become key window. Only apply for FLOWindowPopover type.
 */
@property (nonatomic, assign) BOOL canBecomeKey;

/**
 * This property is used out side of this scope for handling
 * whether the popover floats or not when application resigns active.
 */
@property (nonatomic, assign) BOOL floatsWhenAppResignsActive;

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
 * @param backgroundColor background color for alert window.
 */
- (void)showWithAlertStyleForWindow:(NSWindow *)presentedWindow backgroundColor:(NSColor *)backgroundColor;

@end

#endif /* FLOPopoverProtocols_h */
