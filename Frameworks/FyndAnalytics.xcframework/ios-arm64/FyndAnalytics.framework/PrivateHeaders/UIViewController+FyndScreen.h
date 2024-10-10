#import "FyndSerializableValue.h"

#if TARGET_OS_IPHONE
@import UIKit;

@interface UIViewController (FyndScreen)

+ (void)fynd_seg_swizzleViewDidAppear;
+ (UIViewController *)fynd_seg_rootViewControllerFromView:(UIView *)view;

@end

#endif
