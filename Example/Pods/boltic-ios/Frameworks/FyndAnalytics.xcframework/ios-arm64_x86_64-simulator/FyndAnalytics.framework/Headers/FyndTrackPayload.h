@import Foundation;
#import "FyndPayload.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndTrackPayload)
@interface FyndTrackPayload : FyndPayload

@property(nonatomic, readonly) NSString *event;

@property(nonatomic, readonly, nullable) NSDictionary *properties;

- (instancetype)initWithEvent:(NSString *)event
                   properties:(NSDictionary *_Nullable)properties
                      context:(NSDictionary *)context
                 integrations:(NSDictionary *)integrations;

@end

NS_ASSUME_NONNULL_END
