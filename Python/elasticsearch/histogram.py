from collections import defaultdict
from elasticsearch_dsl import aggs


def time_grouped_aggregation(time_step, timestamp_column='created_at'):
    """Aggregated data using specific time step interval and histogram.
    Bucket name doesn't really matter since its going to be overridden anyway.
    Some of the records distributions like hour or weekday need additional
    tinkering by providing 0 to missing results. In other cases missing records
    can be simply skipped.
    """
    time_distribution = defaultdict(int)
    strategies = {
        'hour': aggs.Bucket().bucket(
            f'bucket_per_{time_step}', 'date_histogram', field=timestamp_column,
            interval='1h', format='hour_minute', min_doc_count=1
        ),
        'day': aggs.Bucket().bucket(
            f'bucket_per_{time_step}', 'date_histogram', field=timestamp_column,
            interval='1d', format='dd/MM/yyyy', min_doc_count=1
        ),
        'weekday': aggs.Bucket().bucket(
            f'bucket_per_{time_step}', 'date_histogram', field=timestamp_column,
            interval='1d', format='e', min_doc_count=1
        ),
        'week': aggs.Bucket().bucket(
            f'bucket_per_{time_step}', 'date_histogram', field=timestamp_column,
            interval='1d', format='ww/MM/yyyy', min_doc_count=1
        ),
        'month': aggs.Bucket().bucket(
            f'bucket_per_{time_step}', 'date_histogram', field=timestamp_column,
            interval='1d', format='MM/yyyy', min_doc_count=1
        )
    }
    if time_step == 'hour':
        for hour in range(0, 24):
            time_distribution[f'{hour:0>2}:00'] = 0
    elif time_step == 'weekday':
        for weekday in range(1, 8):
            time_distribution[f'{weekday}'] = 0

    return strategies[time_step], time_distribution