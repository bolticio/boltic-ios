@import Foundation;
#import "FyndSerializableValue.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndPayload)
@interface FyndPayload : NSObject

@property(nonatomic, readonly) JSON_DICT context;
@property(nonatomic, readonly) JSON_DICT integrations;
@property(nonatomic, strong) NSString *timestamp;
@property(nonatomic, strong) NSString *messageId;
@property(nonatomic, strong) NSString *anonymousId;
@property(nonatomic, strong) NSString *userId;

- (instancetype)initWithContext:(JSON_DICT)context
                   integrations:(JSON_DICT)integrations;

@end

NS_SWIFT_NAME(FyndApplicationLifecyclePayload)
@interface FyndApplicationLifecyclePayload : FyndPayload

@property(nonatomic, strong) NSString *notificationName;

// ApplicationDidFinishLaunching only
@property(nonatomic, strong, nullable) NSDictionary *launchOptions;

@end

NS_SWIFT_NAME(FyndContinueUserActivityPayload)
@interface FyndContinueUserActivityPayload : FyndPayload

@property(nonatomic, strong) NSUserActivity *activity;

@end

NS_SWIFT_NAME(FyndOpenURLPayload)
@interface FyndOpenURLPayload : FyndPayload

@property(nonatomic, strong) NSURL *url;
@property(nonatomic, strong) NSDictionary *options;

@end

NS_ASSUME_NONNULL_END

NS_SWIFT_NAME(FyndRemoteNotificationPayload)
@interface FyndRemoteNotificationPayload : FyndPayload

// FyndEventTypeHandleActionWithForRemoteNotification
@property(nonatomic, strong, nullable) NSString *actionIdentifier;

// FyndEventTypeHandleActionWithForRemoteNotification
// FyndEventTypeReceivedRemoteNotification
@property(nonatomic, strong, nullable) NSDictionary *userInfo;

// FyndEventTypeFailedToRegisterForRemoteNotifications
@property(nonatomic, strong, nullable) NSError *error;

// FyndEventTypeRegisteredForRemoteNotifications
@property(nonatomic, strong, nullable) NSData *deviceToken;

@end
