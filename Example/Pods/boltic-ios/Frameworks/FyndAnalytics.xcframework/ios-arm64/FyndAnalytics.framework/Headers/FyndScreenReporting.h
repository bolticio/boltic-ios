#if TARGET_OS_IPHONE
@import UIKit;
#elif TARGET_OS_OSX
@import Cocoa;
#endif

#import "FyndSerializableValue.h"

/** Implement this protocol to override automatic screen reporting
 */

NS_ASSUME_NONNULL_BEGIN

@protocol FyndScreenReporting
@optional
#if TARGET_OS_IPHONE
- (void)fynd_seg_trackScreen:(UIViewController *)screen name:(NSString *)name;
@property(readonly, nullable) UIViewController *fynd_seg_mainViewController;
#elif TARGET_OS_OSX
- (void)fynd_seg_trackScreen:(NSViewController *)screen name:(NSString *)name;
@property(readonly, nullable) NSViewController *fynd_seg_mainViewController;
#endif
@end

NS_ASSUME_NONNULL_END
