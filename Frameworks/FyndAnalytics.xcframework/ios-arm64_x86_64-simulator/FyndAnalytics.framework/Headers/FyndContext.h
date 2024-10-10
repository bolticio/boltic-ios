//
//  FyndContext.h
//  Analytics
//
//  Created by Tony Xiao on 9/19/16.
//  Copyright © 2016 Segment. All rights reserved.
//

@import Foundation;
#import "FyndIntegration.h"

typedef NS_ENUM(NSInteger, FyndEventType) {
  // Should not happen, but default state
  FyndEventTypeUndefined,
  // Core Tracking Methods
  FyndEventTypeIdentify,
  FyndEventTypeTrack,
  FyndEventTypeScreen,
  FyndEventTypeGroup,
  FyndEventTypeAlias,

  // General utility
  FyndEventTypeReset,
  FyndEventTypeFlush,

  // Remote Notification
  FyndEventTypeReceivedRemoteNotification,
  FyndEventTypeFailedToRegisterForRemoteNotifications,
  FyndEventTypeRegisteredForRemoteNotifications,
  FyndEventTypeHandleActionWithForRemoteNotification,

  // Application Lifecycle
  FyndEventTypeApplicationLifecycle,
  //    DidFinishLaunching,
  //    FyndEventTypeApplicationDidEnterBackground,
  //    FyndEventTypeApplicationWillEnterForeground,
  //    FyndEventTypeApplicationWillTerminate,
  //    FyndEventTypeApplicationWillResignActive,
  //    FyndEventTypeApplicationDidBecomeActive,

  // Misc.
  FyndEventTypeContinueUserActivity,
  FyndEventTypeOpenURL,

} NS_SWIFT_NAME(FyndEventType);

@class FyndAnalytics;
@protocol FyndMutableContext;

NS_SWIFT_NAME(FyndContext)
@interface FyndContext : NSObject <NSCopying>

// Loopback reference to the top level FyndAnalytics object.
// Not sure if it's a good idea to keep this around in the context.
// since we don't really want people to use it due to the circular
// reference and logic (Thus prefixing with underscore). But
// Right now it is required for integrations to work so I guess we'll leave it
// in.
@property(nonatomic, readonly, nonnull) FyndAnalytics *_analytics;
@property(nonatomic, readonly) FyndEventType eventType;

@property(nonatomic, readonly, nullable) NSError *error;
@property(nonatomic, readonly, nullable) FyndPayload *payload;
@property(nonatomic, readonly) BOOL debug;

- (instancetype _Nonnull)initWithAnalytics:(FyndAnalytics *_Nonnull)analytics;

- (FyndContext *_Nonnull)modify:
    (void (^_Nonnull)(id<FyndMutableContext> _Nonnull ctx))modify;

@end

@protocol FyndMutableContext <NSObject>

@property(nonatomic) FyndEventType eventType;
@property(nonatomic, nullable) FyndPayload *payload;
@property(nonatomic, nullable) NSError *error;
@property(nonatomic) BOOL debug;

@end
