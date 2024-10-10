@import Foundation;
@import StoreKit;
#import "FyndAnalytics.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FyndStoreKitTracker)
@interface FyndStoreKitTracker
    : NSObject <SKPaymentTransactionObserver, SKProductsRequestDelegate>

+ (instancetype)trackTransactionsForAnalytics:(FyndAnalytics *)analytics;

@end

NS_ASSUME_NONNULL_END
