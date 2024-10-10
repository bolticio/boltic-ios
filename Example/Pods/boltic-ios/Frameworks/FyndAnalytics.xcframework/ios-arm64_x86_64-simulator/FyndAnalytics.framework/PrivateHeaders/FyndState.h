//
//  FyndState.h
//  Analytics
//
//  Created by Brandon Sneed on 6/9/20.
//  Copyright © 2020 Segment. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class FyndAnalyticsConfiguration;

@interface FyndUserInfo : NSObject
@property(nonatomic, strong) NSString *anonymousId;
@property(nonatomic, strong, nullable) NSString *userId;
@property(nonatomic, strong, nullable) NSDictionary *traits;
@end

@interface FyndPayloadContext : NSObject
@property(nonatomic, readonly) NSDictionary *payload;
@property(nonatomic, strong, nullable) NSDictionary *referrer;
@property(nonatomic, strong, nullable) NSString *deviceToken;

- (void)updateStaticContext;

@end

@interface FyndState : NSObject

@property(nonatomic, readonly) FyndUserInfo *userInfo;
@property(nonatomic, readonly) FyndPayloadContext *context;

@property(nonatomic, strong, nullable)
    FyndAnalyticsConfiguration *configuration;

+ (instancetype)sharedInstance;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
