@import Foundation;
#import "FyndHTTPClient.h"
#import "FyndIntegrationFactory.h"
#import "FyndStorage.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndSegmentIntegrationFactory)
@interface FyndSegmentIntegrationFactory : NSObject <FyndIntegrationFactory>

@property(nonatomic, strong) FyndHTTPClient *client;
@property(nonatomic, strong) id<FyndStorage> userDefaultsStorage;
@property(nonatomic, strong) id<FyndStorage> fileStorage;

- (instancetype)initWithHTTPClient:(FyndHTTPClient *)client
                       fileStorage:(id<FyndStorage>)fileStorage
               userDefaultsStorage:(id<FyndStorage>)userDefaultsStorage;

@end

NS_ASSUME_NONNULL_END
