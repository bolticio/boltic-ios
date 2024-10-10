@import Foundation;
#import "FyndAnalytics.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const fyndkSegmentAPIBaseHost;

NS_SWIFT_NAME(FyndHTTPClient)
@interface FyndHTTPClient : NSObject

@property(nonatomic, strong) FyndRequestFactory requestFactory;
@property(nonatomic, readonly)
    NSMutableDictionary<NSString *, NSURLSession *> *sessionsByWriteKey;
@property(nonatomic, readonly) NSURLSession *genericSession;
@property(nonatomic, weak) id<NSURLSessionDelegate> httpSessionDelegate;

+ (FyndRequestFactory)defaultRequestFactory;
+ (NSString *)authorizationHeader:(NSString *)writeKey;

- (instancetype)initWithRequestFactory:
    (FyndRequestFactory _Nullable)requestFactory;

/**
 * Upload dictionary formatted as per
 * https://segment.com/docs/sources/server/http/#batch. This method will convert
 * the dictionary to json, gzip it and upload the data. It will respond with
 * retry = YES if the batch should be reuploaded at a later time. It will ask to
 * retry for json errors and 3xx/5xx codes, and not retry for 2xx/4xx response
 * codes. NOTE: You need to re-dispatch within the completionHandler onto a
 * desired queue to avoid threading issues. Completion handlers are called on a
 * dispatch queue internal to FyndHTTPClient.
 */
- (nullable NSURLSessionUploadTask *)upload:(JSON_DICT)batch
                                forWriteKey:(NSString *)writeKey
                          completionHandler:
                              (void (^)(BOOL retry))completionHandler;

@end

NS_ASSUME_NONNULL_END
