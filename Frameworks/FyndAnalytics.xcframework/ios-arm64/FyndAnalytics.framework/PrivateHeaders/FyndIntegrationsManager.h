//
//  FyndIntegrationsManager.h
//  Analytics
//
//  Created by Tony Xiao on 9/20/16.
//  Copyright © 2016 Segment. All rights reserved.
//

@import Foundation;
#import "FyndMiddleware.h"

/**
 * Filenames of "Application Support" files where essential data is stored.
 */
extern NSString *_Nonnull const kFyndAnonymousIdFilename;
extern NSString *_Nonnull const kFyndCachedSettingsFilename;

/**
 * NSNotification name, that is posted after integrations are loaded.
 */
extern NSString *_Nonnull FyndAnalyticsIntegrationDidStart;

@class FyndAnalytics;

NS_SWIFT_NAME(FyndIntegrationsManager)
@interface FyndIntegrationsManager : NSObject

// Exposed for testing.
+ (BOOL)isIntegration:(NSString *_Nonnull)key
     enabledInOptions:(NSDictionary *_Nonnull)options;
+ (BOOL)isTrackEvent:(NSString *_Nonnull)event
    enabledForIntegration:(NSString *_Nonnull)key
                   inPlan:(NSDictionary *_Nonnull)plan;

// @Deprecated - Exposing for backward API compat reasons only
@property(nonatomic, readonly)
    NSMutableDictionary *_Nonnull registeredIntegrations;

- (instancetype _Nonnull)initWithAnalytics:(FyndAnalytics *_Nonnull)analytics;

// @Deprecated - Exposing for backward API compat reasons only
- (NSString *_Nonnull)getAnonymousId;
- (void)saveAnonymousId:(NSString *_Nonnull)anonymousId;

@end

@interface FyndIntegrationsManager (FyndMiddleware) <FyndMiddleware>

@end
