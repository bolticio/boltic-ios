//
//  FyndUtils.h
//
//

@import Foundation;
#import "FyndAnalyticsUtils.h"
#import "FyndSerializableValue.h"

NS_ASSUME_NONNULL_BEGIN

@class FyndAnalyticsConfiguration;
@class FyndReachability;

NS_SWIFT_NAME(FyndUtilities)
@interface FyndUtils : NSObject

+ (void)saveAPIHost:(nonnull NSString *)apiHost;
+ (nonnull NSString *)getAPIHost;
+ (nullable NSURL *)getAPIHostURL;

+ (NSData *_Nullable)dataFromPlist:(nonnull id)plist;
+ (id _Nullable)plistFromData:(NSData *)data;

+ (id _Nullable)traverseJSON:(id _Nullable)object
       andReplaceWithFilters:(NSDictionary<NSString *, NSString *> *)patterns;

@end

BOOL fyndisUnitTesting(void);

NSString *_Nullable fynddeviceTokenToString(NSData *_Nullable deviceToken);
NSString *fyndGetDeviceModel(void);
BOOL fyndGetAdTrackingEnabled(FyndAnalyticsConfiguration *configuration);
NSDictionary *fyndgetStaticContext(FyndAnalyticsConfiguration *configuration,
                               NSString *_Nullable deviceToken);
NSDictionary *fyndGetLiveContext(FyndReachability *reachability,
                             NSDictionary *_Nullable referrer,
                             NSDictionary *_Nullable traits);

NSString *fyndGenerateUUIDString(void);

#if TARGET_OS_IPHONE
NSDictionary *fyndmobileSpecifications(FyndAnalyticsConfiguration *configuration,
                                   NSString *_Nullable deviceToken);
#elif TARGET_OS_OSX
NSDictionary *desktopSpecifications(FyndAnalyticsConfiguration *configuration,
                                    NSString *_Nullable deviceToken);
#endif

// Date Utils
NSString *fyndIso8601FormattedString(NSDate *date);
NSString *fyndiso8601NanoFormattedString(NSDate *date);

void fyndTrimQueue(NSMutableArray *array, NSUInteger size);

// Async Utils
dispatch_queue_t
fynd_seg_dispatch_queue_create_specific(const char *label,
                                   dispatch_queue_attr_t _Nullable attr);
BOOL fynd_seg_dispatch_is_on_specific_queue(dispatch_queue_t queue);
void fynd_seg_dispatch_specific(dispatch_queue_t queue, dispatch_block_t block,
                           BOOL waitForCompletion);
void fynd_seg_dispatch_specific_async(dispatch_queue_t queue,
                                 dispatch_block_t block);
void fynd_seg_dispatch_specific_sync(dispatch_queue_t queue, dispatch_block_t block);

// JSON Utils

JSON_DICT FyndCoerceDictionary(NSDictionary *_Nullable dict);

NSString *_Nullable FyndIDFA(void);

NSString *FyndEventNameForScreenTitle(NSString *title);

@interface NSJSONSerialization (Serializable)
+ (BOOL)isOfSerializableType:(id)obj;
@end

// Deep copy and check NSCoding conformance
@protocol FyndSerializableDeepCopy <NSObject>
- (id _Nullable)serializableMutableDeepCopy;
- (id _Nullable)serializableDeepCopy;
@end

@interface NSDictionary (SerializableDeepCopy) <FyndSerializableDeepCopy>
@end

@interface NSArray (SerializableDeepCopy) <FyndSerializableDeepCopy>
@end

@interface NSDictionary (PListJSON)
- (NSDictionary *)plistCompatible;
@end

@interface NSArray (PListJSON)
- (NSDictionary *)plistCompatible;
@end

NS_ASSUME_NONNULL_END
