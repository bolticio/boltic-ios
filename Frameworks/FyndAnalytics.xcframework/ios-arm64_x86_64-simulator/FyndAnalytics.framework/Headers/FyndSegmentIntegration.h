@import Foundation;
#import "FyndHTTPClient.h"
#import "FyndIntegration.h"
#import "FyndStorage.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kFyndSegmentDestinationName;

extern NSString *const FyndSegmentDidSendRequestNotification;
extern NSString *const FyndSegmentRequestDidSucceedNotification;
extern NSString *const FyndSegmentRequestDidFailNotification;

/**
 * Filenames of "Application Support" files where essential data is stored.
 */
extern NSString *const kFyndUserIdFilename;
extern NSString *const kFyndQueueFilename;
extern NSString *const kFyndTraitsFilename;

NS_SWIFT_NAME(FyndSegmentIntegration)
@interface FyndSegmentIntegration : NSObject <FyndIntegration>

- (id)initWithAnalytics:(FyndAnalytics *)analytics
             httpClient:(FyndHTTPClient *)httpClient
            fileStorage:(id<FyndStorage>)fileStorage
    userDefaultsStorage:(id<FyndStorage>)userDefaultsStorage;

@end

NS_ASSUME_NONNULL_END
