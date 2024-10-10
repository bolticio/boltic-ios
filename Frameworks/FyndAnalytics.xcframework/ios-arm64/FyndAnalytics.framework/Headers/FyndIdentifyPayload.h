@import Foundation;
#import "FyndPayload.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndIdentifyPayload)
@interface FyndIdentifyPayload : FyndPayload

@property(nonatomic, readonly, nullable) JSON_DICT traits;

- (instancetype)initWithUserId:(NSString *)userId
                   anonymousId:(NSString *_Nullable)anonymousId
                        traits:(JSON_DICT _Nullable)traits
                       context:(JSON_DICT)context
                  integrations:(JSON_DICT)integrations;

@end

NS_ASSUME_NONNULL_END
