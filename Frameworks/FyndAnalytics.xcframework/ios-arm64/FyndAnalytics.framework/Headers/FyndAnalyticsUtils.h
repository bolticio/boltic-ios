@import Foundation;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Logging

void FyndSetShowDebugLogs(BOOL showDebugLogs);
void FyndLog(NSString *format, ...);

#pragma mark - Serialization Extensions

NS_SWIFT_NAME(FyndSegmentSerializable)
@protocol FyndSerializable
/**
 Serialize objects to a type supported by NSJSONSerializable.  Objects that
 conform to this protocol should return values of type NSArray, NSDictionary,
 NSString, NSNumber.  Useful for extending objects of your own such that they
 can be serialized on the way to Segment and destinations.
 */
- (id)serializeToAppropriateType;
@end

NS_ASSUME_NONNULL_END
