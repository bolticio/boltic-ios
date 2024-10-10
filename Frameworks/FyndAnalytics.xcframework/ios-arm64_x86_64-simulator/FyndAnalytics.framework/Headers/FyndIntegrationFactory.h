@import Foundation;
#import "FyndAnalytics.h"
#import "FyndIntegration.h"

NS_ASSUME_NONNULL_BEGIN

@class FyndAnalytics;

@protocol FyndIntegrationFactory

/**
 * Attempts to create an adapter with the given settings. Returns the adapter if
 * one was created, or null if this factory isn't capable of creating such an
 * adapter.
 */
- (id<FyndIntegration>)createWithSettings:(NSDictionary *)settings
                             forAnalytics:(FyndAnalytics *)analytics;

/** The key for which this factory can create an Integration. */
- (NSString *)key;

@end

NS_ASSUME_NONNULL_END
