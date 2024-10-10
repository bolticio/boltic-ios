#import "FyndHTTPClient.h"
#import "FyndIntegration.h"
#import "FyndIntegrationFactory.h"

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(FyndWebhookIntegrationFactory)
@interface FyndWebhookIntegrationFactory : NSObject <FyndIntegrationFactory>

@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *webhookUrl;

- (instancetype)initWithName:(NSString *)name webhookUrl:(NSString *)webhookUrl;

@end

NS_ASSUME_NONNULL_END