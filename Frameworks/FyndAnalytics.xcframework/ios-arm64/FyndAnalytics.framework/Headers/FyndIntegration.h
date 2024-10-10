@import Foundation;
#import "FyndAliasPayload.h"
#import "FyndContext.h"
#import "FyndGroupPayload.h"
#import "FyndIdentifyPayload.h"
#import "FyndScreenPayload.h"
#import "FyndTrackPayload.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndIntegration)
@protocol FyndIntegration <NSObject>

@optional
// Identify will be called when the user calls either of the following:
// 1. [[FyndAnalytics sharedInstance] identify:someUserId];
// 2. [[FyndAnalytics sharedInstance] identify:someUserId traits:someTraits];
// 3. [[FyndAnalytics sharedInstance] identify:someUserId traits:someTraits
// options:someOptions];
// @see https://segment.com/docs/spec/identify/
- (void)identify:(FyndIdentifyPayload *)payload;

// Track will be called when the user calls either of the following:
// 1. [[FyndAnalytics sharedInstance] track:someEvent];
// 2. [[FyndAnalytics sharedInstance] track:someEvent
// properties:someProperties];
// 3. [[FyndAnalytics sharedInstance] track:someEvent properties:someProperties
// options:someOptions];
// @see https://segment.com/docs/spec/track/
- (void)track:(FyndTrackPayload *)payload;

// Screen will be called when the user calls either of the following:
// 1. [[FyndAnalytics sharedInstance] screen:someEvent];
// 2. [[FyndAnalytics sharedInstance] screen:someEvent
// properties:someProperties];
// 3. [[FyndAnalytics sharedInstance] screen:someEvent properties:someProperties
// options:someOptions];
// @see https://segment.com/docs/spec/screen/
- (void)screen:(FyndScreenPayload *)payload;

// Group will be called when the user calls either of the following:
// 1. [[FyndAnalytics sharedInstance] group:someGroupId];
// 2. [[FyndAnalytics sharedInstance] group:someGroupId traits:];
// 3. [[FyndAnalytics sharedInstance] group:someGroupId traits:someGroupTraits
// options:someOptions];
// @see https://segment.com/docs/spec/group/
- (void)group:(FyndGroupPayload *)payload;

// Alias will be called when the user calls either of the following:
// 1. [[FyndAnalytics sharedInstance] alias:someNewId];
// 2. [[FyndAnalytics sharedInstance] alias:someNewId options:someOptions];
// @see https://segment.com/docs/spec/alias/
- (void)alias:(FyndAliasPayload *)payload;

// Reset is invoked when the user logs out, and any data saved about the user
// should be cleared.
- (void)reset;

// Flush is invoked when any queued events should be uploaded.
- (void)flush;

// App Delegate Callbacks

// Callbacks for notifications changes.
// ------------------------------------
- (void)receivedRemoteNotification:(NSDictionary *)userInfo;
- (void)failedToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)registeredForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)handleActionWithIdentifier:(NSString *)identifier
             forRemoteNotification:(NSDictionary *)userInfo;

// Callbacks for app state changes
// -------------------------------

- (void)applicationDidFinishLaunching:(NSNotification *)notification;
- (void)applicationDidEnterBackground;
- (void)applicationWillEnterForeground;
- (void)applicationWillTerminate;
- (void)applicationWillResignActive;
- (void)applicationDidBecomeActive;

- (void)continueUserActivity:(NSUserActivity *)activity;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options;

@end

NS_ASSUME_NONNULL_END
